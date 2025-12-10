#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Parametric constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    std::cout << "Bureaucrat constructor with values called" << std::endl;
    
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

// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

// Getters
const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

// Increment grade
void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

// Decrement grade
void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

// Method to sign a form
void Bureaucrat::signForm(AForm& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

// NEW: Method to execute a form
void Bureaucrat::executeForm(const AForm& form) const
{
    try
    {
        form.execute(*this);  // Try to execute the form
        // If successful, print success message
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        // If failed, print error message
        std::cout << _name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high! (minimum is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low! (maximum is 150)";
}

// Overload of << operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}