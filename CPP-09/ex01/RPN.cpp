#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other)
{
    _stack = other._stack;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _stack = other._stack;
    return (*this);
}

// Checks if token is an operator (+, -, *, /)
bool RPN::_isOperator(const std::string& token) const
{
    if (token.length() != 1)
        return (false);
    return (token[0] == '+' || token[0] == '-' || 
            token[0] == '*' || token[0] == '/');
}

// Checks if token is a valid single digit number (0-9)
bool RPN::_isNumber(const std::string& token) const
{
    if (token.length() != 1)
        return (false);
    return (token[0] >= '0' && token[0] <= '9');
}

// Performs arithmetic operation
int RPN::_performOperation(int operand1, int operand2, char op) const
{
    if (op == '+')
        return (operand1 + operand2);
    if (op == '-')
        return (operand1 - operand2);
    if (op == '*')
        return (operand1 * operand2);

    if (op == '/')
    {
        if (operand2 == 0)
            throw std::runtime_error("Error: division by zero");
        return (operand1 / operand2);
    }
    throw std::runtime_error("Error: unknown operator");
}

// Processes a single token (number or operator)
void RPN::_processToken(const std::string& token)
{
    if (_isNumber(token))
    {
        int number = token[0] - '0';    // Convert char to int
        _stack.push(number);            // Add to top of the stack
    }
    else if (_isOperator(token))
    {
        if (_stack.size() < 2)
            throw std::runtime_error("Error: not enough operands");
        
        int operand2 = _stack.top();    // Get second operand (top of stack)
        _stack.pop();                   // Remove it from stack
        int operand1 = _stack.top();    // Then first operand
        _stack.pop();
        
        int result = _performOperation(operand1, operand2, token[0]);
        _stack.push(result);            // Add result to top of stack
    }
    else
        throw std::runtime_error("Error: invalid token");
}

// Main calculation function
void RPN::calculate(const std::string& expression)
{
    std::istringstream iss(expression); // Divide our string word by word
    std::string token;
    
    // Good safety practice: make sure stack is empty before starting
    while (!_stack.empty())
        _stack.pop();
    
    // Process each token
    while (iss >> token)        // Skip spaces and read next word. If success -> process token.
        _processToken(token);
    
    // Check final result
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    
    std::cout << _stack.top() << std::endl;
}