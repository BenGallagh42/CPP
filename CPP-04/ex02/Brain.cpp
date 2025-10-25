#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "[Brain] has been created." << std::endl;
    for (int i = 0; i < 100; ++i)
        ideas[i] = "empty idea";
}

Brain::Brain(const Brain& other)
{
    std::cout << "[Brain] Copy constructor called." << std::endl;
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = other.ideas[i];  // Deep copy
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        std::cout << "[Brain] Assignment operator called." << std::endl;
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = other.ideas[i];  // Deep copy
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "[Brain] has been removed." << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}