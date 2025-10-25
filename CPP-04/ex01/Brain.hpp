#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string ideas[100]; // Array of 100 strings
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
};

#endif