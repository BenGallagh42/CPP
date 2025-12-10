#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

// Parametric constructor - initializes base class with fixed grades
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor with target called" << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

// Assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Getter
const std::string& ShrubberyCreationForm::getTarget() const
{
    return _target;
}

// Implementation of executeAction - creates file with ASCII trees
void ShrubberyCreationForm::executeAction() const
{
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());  // c_str() for C++98 compatibility
    
    if (!file.is_open())
    {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }
    
    // Write ASCII trees to file
    file << "      /|\\\n";
    file << "     //|\\\\\n";
    file << "    ///|\\\\\\\n";
    file << "   ////|\\\\\\\\\n";
    file << "  /////|\\\\\\\\\\\n";
    file << "      |||\n";
    file << "      |||\n";
    file << "      |||\n";
    
    file.close();
    std::cout << "Shrubbery has been planted at " << _target << std::endl;
}