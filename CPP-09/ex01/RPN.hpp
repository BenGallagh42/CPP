#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN {
private:
    std::stack<int> _stack; 
    // Stack is perfect for RPN, we stack operands, then unstack to make calculation

    bool    _isOperator(const std::string& token) const;
    bool    _isNumber(const std::string& token) const;
    int     _performOperation(int operand1, int operand2, char op) const;
    void    _processToken(const std::string& token);

public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    void calculate(const std::string& expression);
};

#endif