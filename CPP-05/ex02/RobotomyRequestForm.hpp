#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

class RobotomyRequestForm : public AForm {
private:
    std::string _target;

public:
    // Orthodox Canonical Form
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    // Getter
    const std::string& getTarget() const;

    // Implementation of pure virtual method
    virtual void executeAction() const;
};

#endif