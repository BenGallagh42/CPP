#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Parametric constructor - validates grade before assigning
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    std::cout << "Bureaucrat constructor with values called" << std::endl;
    
    // Validate grade range before assignment
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    
    _grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) 
    : _name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Assignment operator - note: cannot reassign const _name
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &other) {
        // Cannot assign _name because it's const
        _grade = other._grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

// Getter for name
const std::string& Bureaucrat::getName() const
{
    return _name;
}

// Getter for grade
int Bureaucrat::getGrade() const
{
    return _grade;
}

// Increment grade (decrease number: 3 -> 2)
void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)  // Check if new grade would be too high
        throw GradeTooHighException();
    _grade--;
}

// Decrement grade (increase number: 3 -> 4)
void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)  // Check if new grade would be too low
        throw GradeTooLowException();
    _grade++;
}

// Exception: what() method returns error message
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high! (minimum is 1)";
}

// Exception: what() method returns error message
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low! (maximum is 150)";
}

// Overload of << operator for formatted output
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}