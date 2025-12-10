#include "Intern.hpp"

// Default constructor
Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern& other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;  // Intern has no attributes to copy
}

// Assignment operator
Intern& Intern::operator=(const Intern& other)
{
    std::cout << "Intern assignment operator called" << std::endl;
    (void)other;  // Intern has no attributes to assign
    return *this;
}

// Destructor
Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

// Helper method - returns index of form type or -1 if unknown
int Intern::getFormIndex(const std::string& formName) const
{
    // Array of known form names
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    // Find matching form name
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
            return i;
    }
    
    return -1;  // Unknown form
}

// Factory method - creates appropriate form based on name
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    // Get form index
    int formIndex = getFormIndex(formName);
    
    // Array of form creation functions (function pointer approach avoided for clarity)
    AForm* form = NULL;
    
    // Create appropriate form based on index
    switch (formIndex)
    {
        case 0:  // shrubbery creation
            form = new ShrubberyCreationForm(target);
            break;
        case 1:  // robotomy request
            form = new RobotomyRequestForm(target);
            break;
        case 2:  // presidential pardon
            form = new PresidentialPardonForm(target);
            break;
        default:  // unknown form
            throw UnknownFormException();
    }
    
    // Print success message
    std::cout << "Intern creates " << form->getName() << std::endl;
    
    return form;
}

// Exception message
const char* Intern::UnknownFormException::what() const throw()
{
    return "Form type unknown";
}