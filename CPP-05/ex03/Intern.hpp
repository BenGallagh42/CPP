#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    // Orthodox Canonical Form
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    // Factory method - creates forms based on name
    AForm* makeForm(const std::string& formName, const std::string& target) const;

    // Exception for unknown form
    class UnknownFormException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

private:
    // Helper method to check form name
    int getFormIndex(const std::string& formName) const;
};

#endif