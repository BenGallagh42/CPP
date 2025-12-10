#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
private:
    const std::string _name;  // Name cannot be changed after initialization
    int _grade;               // Grade between 1 (highest) and 150 (lowest)

public:
    // Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters - const methods because they don't modify the object
    const std::string& getName() const;
    int getGrade() const;

    // Grade manipulation methods
    void incrementGrade();  // Increases grade (decreases number: 3 -> 2)
    void decrementGrade();  // Decreases grade (increases number: 3 -> 4)

    // Nested exception classes
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

// Overload of insertion operator for easy printing
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif