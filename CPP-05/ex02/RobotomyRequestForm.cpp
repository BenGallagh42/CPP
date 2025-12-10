#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

// Parametric constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor with target called" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

// Assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Getter
const std::string& RobotomyRequestForm::getTarget() const
{
    return _target;
}

// Implementation of executeAction - 50% success rate
void RobotomyRequestForm::executeAction() const
{
    std::cout << "* Drilling noises: BZZZZZZZ BZZZZZ BZZZ *" << std::endl;
    
    // Use current time as seed for random (only once per program execution ideally)
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    // 50% chance of success
    if (std::rand() % 2 == 0)
    {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
    }
}