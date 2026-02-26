# ⚙️ C++ Modules — École 42

> A progressive journey through C++ from the ground up — OOP, memory management, templates, STL, and beyond.

---

## 📚 Overview

This repository contains all C++ module projects completed as part of the **École 42** curriculum. Each module introduces new C++ concepts, building from basic syntax to advanced patterns used in real-world systems programming.

---

## 🗂️ Modules

### [CPP-00](./CPP-00) — The Basics
Getting comfortable with C++ syntax, namespaces, classes, and I/O streams.
| Exercise | Description |
|----------|-------------|
| ex00 | `megaphone` — String manipulation & uppercasing |
| ex01 | `PhoneBook` — Classes, member functions, formatted output |
| ex02 | `Account` — Class reconstruction from logs |

---

### [CPP-01](./CPP-01) — Memory & References
Stack vs heap allocation, pointers, references, and file I/O.
| Exercise | Description |
|----------|-------------|
| ex00 | `Zombie` — Stack vs heap object allocation |
| ex01 | `ZombieHorde` — Array allocation with `new[]` |
| ex02 | References — Pointer vs reference comparison |
| ex03 | `HumanA / HumanB` — References vs pointers as class members |
| ex04 | File I/O — Read and replace strings in files |
| ex05 | `Harl` — Pointers to member functions |
| ex06 | `Harl 2.0` — Switch-based filtering with member function pointers |

---

### [CPP-02](./CPP-02) — Ad-hoc Polymorphism & Fixed-Point Numbers
Operator overloading, canonical class form, and fixed-point arithmetic.
| Exercise | Description |
|----------|-------------|
| ex00 | `Fixed` — Orthodox Canonical Form introduction |
| ex01 | `Fixed` — Constructors, conversion, stream operator |
| ex02 | `Fixed` — Full operator overloading (arithmetic, comparison, increment) |

---

### [CPP-03](./CPP-03) — Inheritance
Class hierarchies, derived classes, and constructor chaining.
| Exercise | Description |
|----------|-------------|
| ex00 | `ClapTrap` — Base class with attributes and member functions |
| ex01 | `ScavTrap` — Derived class, constructor/destructor chain |
| ex02 | `FragTrap` — Multiple inheritance levels |

---

### [CPP-04](./CPP-04) — Subtype Polymorphism & Abstract Classes
Virtual functions, pure virtual classes, interfaces, and deep copy.
| Exercise | Description |
|----------|-------------|
| ex00 | `Animal / Dog / Cat` — Virtual functions, polymorphic behavior |
| ex01 | `Brain` — Deep copy, heap-allocated members |
| ex02 | `AAnimal` — Abstract classes, preventing direct instantiation |

---

### [CPP-05](./CPP-05) — Exceptions
Exception handling with custom exception classes and form processing.
| Exercise | Description |
|----------|-------------|
| ex00 | `Bureaucrat` — Custom exceptions, grade bounds enforcement |
| ex01 | `Form` — Form signing with grade validation |
| ex02 | `AForm` — Abstract forms: `ShrubberyCreation`, `RobotomyRequest`, `PresidentialPardon` |
| ex03 | `Intern` — Factory pattern for form creation |

---

### [CPP-06](./CPP-06) — Casting
Static, dynamic, reinterpret, and const casts in C++.
| Exercise | Description |
|----------|-------------|
| ex00 | `ScalarConverter` — Literal type detection and conversion |
| ex01 | `Serializer` — `reinterpret_cast` with pointer serialization |
| ex02 | Type identification — `dynamic_cast` with class hierarchy |

---

### [CPP-07](./CPP-07) — Templates
Function templates, template specialization, and generic containers.
| Exercise | Description |
|----------|-------------|
| ex00 | `whatever.hpp` — Generic `swap`, `min`, `max` |
| ex01 | `iter.hpp` — Array iteration with function pointer template |
| ex02 | `Array<T>` — Generic array class with bounds checking |

---

### [CPP-08](./CPP-08) — STL Containers & Algorithms
Templated algorithms, iterators, and container adapters.
| Exercise | Description |
|----------|-------------|
| ex00 | `easyfind` — Template function with STL iterators |
| ex01 | `Span` — Min/max span over a container |
| ex02 | `MutantStack` — Stack with exposed iterators |

---

### [CPP-09](./CPP-09) — STL in Practice
Real-world use of `std::map`, `std::stack`, and `std::deque`.
| Exercise | Description |
|----------|-------------|
| ex00 | `BitcoinExchange` — Date-indexed map lookup from CSV |
| ex01 | `RPN` — Reverse Polish Notation calculator with stack |
| ex02 | `PmergeMe` — Ford-Johnson merge-insert sort on two containers |

---

## 🔧 Build

Each exercise has its own `Makefile`. To compile any exercise:

```bash
cd CPP-XX/exXX
make
```

Standard targets available: `make`, `make clean`, `make fclean`, `make re`

---

## 🧠 Concepts Covered

`OOP` · `Inheritance` · `Polymorphism` · `Templates` · `STL` · `Exceptions` · `Memory Management` · `Operator Overloading` · `Type Casting` · `Canonical Form` · `Abstract Classes` · `Iterators`

---

## 🏫 About

Projects completed at **[École 42](https://42.fr)** — a peer-to-peer coding school with no teachers, no MOOCs, and no hand-holding. Every line of code was written, debugged, and defended in peer evaluations.

---

*"Any fool can write code that a computer can understand. Good programmers write code that humans can understand."*
