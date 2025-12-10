#include "Form.hpp"

// Default constructor
Form::Form() 
    : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

// Parametric constructor - validates grades before assignment
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form constructor with values called" << std::endl;
    
    // Validate gradeToSign and gradeToExecute
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy constructor
Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

// Assignment operator - cannot reassign const attributes
Form& Form::operator=(const Form& other)
{
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &other)
    {
        // Can only copy _isSigned (other attributes are const)
        _isSigned = other._isSigned;
    }
    return *this;
}

// Destructor
Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

// Getter for name
const std::string& Form::getName() const
{
    return _name;
}

// Getter for signed status
bool Form::getIsSigned() const
{
    return _isSigned;
}

// Getter for grade to sign
int Form::getGradeToSign() const
{
    return _gradeToSign;
}

// Getter for grade to execute
int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

// Method to sign the form
void Form::beSigned(const Bureaucrat& bureaucrat)
{
    // Check if bureaucrat's grade is high enough (remember: lower number = higher grade)
    if (bureaucrat.getGrade() > _gradeToSign)
    {
        throw GradeTooLowException();
    }
    // If grade is sufficient, sign the form
    _isSigned = true;
}

// Exception: what() method returns error message
const char* Form::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

// Exception: what() method returns error message
const char* Form::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

// Overload of << operator for printing form information
std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form " << form.getName() 
        << " [Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Grade to sign: " << form.getGradeToSign()
        << ", Grade to execute: " << form.getGradeToExecute() << "]";
    return out;
}