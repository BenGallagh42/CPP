#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

// Abstract class - cannot be instantiated
class AForm {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    // Orthodox Canonical Form
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();  // Virtual destructor for polymorphism

    // Getters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Method to sign the form
    void beSigned(const Bureaucrat& bureaucrat);

    // NEW: Method to execute the form (checks requirements then calls execute implementation)
    void execute(const Bureaucrat& executor) const;

    // Pure virtual method - must be implemented by derived classes
    virtual void executeAction() const = 0;

    // Exception classes
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif