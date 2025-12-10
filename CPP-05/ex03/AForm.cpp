#include "AForm.hpp"

// Default constructor
AForm::AForm() 
    : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

// Parametric constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "AForm constructor with values called" << std::endl;
    
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

// Assignment operator
AForm& AForm::operator=(const AForm& other)
{
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

// Virtual destructor
AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

// Getters
const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

// Method to sign the form
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
    {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

// NEW: Method to execute - checks requirements then calls executeAction()
void AForm::execute(const Bureaucrat& executor) const
{
    // Check if form is signed
    if (!_isSigned)
    {
        throw FormNotSignedException();
    }
    // Check if executor's grade is high enough
    if (executor.getGrade() > _gradeToExecute)
    {
        throw GradeTooLowException();
    }
    // If all checks pass, execute the specific action
    executeAction();
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "form is not signed";
}

// Overload of << operator
std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "Form " << form.getName() 
        << " [Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Grade to sign: " << form.getGradeToSign()
        << ", Grade to execute: " << form.getGradeToExecute() << "]";
    return out;
}