#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <sstream>

PhoneBook::PhoneBook() : index(0), count(0) {}

void PhoneBook::addContact()
{
	if (count >= 8)
		index = 0;
	std::string fn, ln, nn, pn, ds;
	while (1)
	{
		std::cout << "Enter First Name: ";
		if (!std::getline(std::cin, fn))
		{
			std::cout << std::endl;
			std::cout << "Ending program." << std::endl;
			exit(1);
		}
		if (!fn.empty())
			break;
		std::cout << "Error: field cannot be left empty. Try again." << std::endl;
	}
	while (1)
	{
		std::cout << "Enter Last Name: ";
		if (!std::getline(std::cin, ln))
		{
			std::cout << std::endl;
			std::cout << "Ending program." << std::endl;
			exit(1);
		}
		if (!ln.empty())
			break;
		std::cout << "Error: field cannot be left empty. Try again." << std::endl;
	}
	while (1)
	{
		std::cout << "Enter Nickname: ";
		if (!std::getline(std::cin, nn))
		{
			std::cout << std::endl;
			std::cout << "Ending program." << std::endl;
			exit(1);
		}
		if (!nn.empty())
			break;
		std::cout << "Error: field cannot be left empty. Try again." << std::endl;
	}
	while (1)
	{
		std::cout << "Enter Phone Number: ";
		if (!std::getline(std::cin, pn))
		{
			std::cout << std::endl;
			std::cout << "Ending program." << std::endl;
			exit(1);
		}
		if (!pn.empty())
			break;
		std::cout << "Error: field cannot be left empty. Try again." << std::endl;
	}
	while (1)
	{
		std::cout << "Enter Darkest Secret: ";
		if (!std::getline(std::cin, ds))
		{
			std::cout << std::endl;
			std::cout << "Ending program." << std::endl;
			exit(1);
		}
		if (!ds.empty())
			break;
		std::cout << "Error: field cannot be left empty. Try again." << std::endl;
	}
	contacts[index].setContact(fn, ln, nn, pn, ds);
	index = (index +1) % 8;
	if (count < 8)
		count++;
}

void PhoneBook::searchContact()
{
	int i = 0;

	while (i < count)
	{
		std::cout << std::right << std::setw(10) << i << "|";
		std::string firstName = contacts[i].getFirstName();
		std::string lastName = contacts[i].getLastName();
		std::string nickname = contacts[i].getNickname();
		std::string firstNameDisplay = firstName;
		std::string lastNameDisplay = lastName;
		std::string nicknameDisplay = nickname;
		if (firstName.length() > 9)
		{
			firstNameDisplay = firstName.substr(0, 9);
			firstNameDisplay += ".";
		}
		if (lastName.length() > 9)
		{
			lastNameDisplay = lastName.substr(0, 9);
			lastNameDisplay += ".";
		}
		if (nickname.length() > 9)
		{
			nicknameDisplay = nickname.substr(0, 9);
			nicknameDisplay += ".";
		}
		std::cout << std::right << std::setw(10) << firstNameDisplay << "|";
		std::cout << std::right << std::setw(10) << lastNameDisplay << "|";
		std::cout << std::right << std::setw(10) << nicknameDisplay << "|" << std::endl;
		i++;
	}
	int		idx;
	std::string input;
	while (true)
	{
		std::cout << "Enter index: " << std::flush;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			std::cout << "Ending program." << std::endl;
			exit(1);
		}
		std::istringstream inputString(input);
		if (inputString >> idx && (inputString >> std::ws, inputString.eof()) && idx >= 0 && idx < count)
			break;
		else
			std::cout << "Error: Invalid input. Please enter a valid index (0-" << count - 1 << ")." << std::endl;
	}
	contacts[idx].displayContact();
}

void PhoneBook::run()
{
	std::string command;
	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl;
			std::cout << "Ending program." << std::endl;
			exit(1);
		}
		if (command == "EXIT")
		{
			std::cout << "Ending program." << std::endl;
			exit(1);
		}
		if (command == "ADD")
			addContact();
		if (command == "SEARCH")
		{
			if (count == 0)
			{
				std::cout << "Phonebook is empty. No contacts to search." << std::endl;
				continue;
			}
			searchContact();
		}
	}
}