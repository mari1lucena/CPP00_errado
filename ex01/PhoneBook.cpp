#include "PhoneBook.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

PhoneBook::PhoneBook()
	: contactCount(0), nextIndex(0)
{
}

void	PhoneBook::addContact()
{
	Contact	newContact;

	if (!newContact.fillContact())
		return ;
	contacts[nextIndex] = newContact;
	nextIndex = (nextIndex + 1) % 8;
	if (contactCount < 8)
		contactCount++;
	std::cout << "Contact added successfully." << std::endl;
}

static bool	getIndex(const std::string &input, int &index)
{
	std::stringstream	stream(input);
	char				extra;

	if (!(stream >> index))
		return (false);
	if (stream >> extra)
		return (false);
	return (true);
}

void	PhoneBook::searchContact() const
{
	std::string	input;
	int			index;
	int			i;

	if (contactCount == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	i = 0;
	while (i < contactCount)
	{
		contacts[i].displaySummary(i);
		i++;
	}
	std::cout << "Enter an index: ";
	if (!std::getline(std::cin, input))
		return ;
	if (!getIndex(input, index)
		|| index < 0
		|| index >= contactCount)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	contacts[index].displayContact();
}