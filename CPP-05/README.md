# CPP Module 05 - Repetition and Exceptions

Exception handling in C++ through a bureaucratic form system.

## Exercises

**ex00**: Bureaucrat class with grade validation (1-150) and custom exceptions

**ex01**: Form class requiring specific grades to sign

**ex02**: Abstract forms with concrete implementations (Shrubbery, Robotomy, Presidential)

**ex03**: Intern factory class to create forms

## Key Concepts

- Custom exception classes
- Abstract classes and pure virtual functions
- Polymorphism and inheritance
- Factory design pattern
- Memory management with `new`/`delete`

## Notes

- Grade 1 = highest, 150 = lowest
- Increment grade: decreases number (3 → 2)
- All classes follow Orthodox Canonical Form
- ex03: Remember to `delete` forms returned by `makeForm()`