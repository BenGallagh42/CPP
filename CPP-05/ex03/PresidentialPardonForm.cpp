#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

// Parametric constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm constructor with target called" << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

// Assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// Getter
const std::string& PresidentialPardonForm::getTarget() const
{
    return _target;
}

// Implementation of executeAction - presidential pardon message
void PresidentialPardonForm::executeAction() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}