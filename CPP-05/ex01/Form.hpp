#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
private:
    const std::string _name;          // Form name (constant)
    bool _isSigned;                   // Signature status
    const int _gradeToSign;           // Minimum grade required to sign
    const int _gradeToExecute;        // Minimum grade required to execute

public:
    // Orthodox Canonical Form
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // Getters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Method to sign the form
    void beSigned(const Bureaucrat& bureaucrat);

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
};

// Overload of insertion operator
std::ostream& operator<<(std::ostream& out, const Form& form);

#endif