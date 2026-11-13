
#include "Contact.hpp"

#include <cctype>
#include <iomanip>
#include <iostream>

Contact::Contact()
{
}

static bool getField(const std::string &message, std::string &field)
{
    field.clear();

    while (field.empty())
    {
        std::cout << message;

        if (!std::getline(std::cin, field))
            return (false);

        if (field.empty())
            std::cout << "Field cannot be empty." << std::endl;
    }
    return (true);
}

bool Contact::fillContact()
{
    if (!getField("First name: ", firstName))
        return (false);
    if (!getField("Last name: ", lastName))
        return (false);
    if (!getField("Nickname: ", nickname))
        return (false);
    if (!getField("Phone number: ", phoneNumber))
        return (false);
    if (!getField("Darkest secret: ", darkestSecret))
        return (false);
    return (true);
}


static std::string formatColumn(const std::string &text)
{
    std::string result = text;

    for (std::string::size_type i = 0; i < result.length(); i++)
    {
        if (result[i] == '\t' || result[i] == '\n'
            || result[i] == '\r')
            result[i] = ' ';
    }
    if (result.length() > 10)
        return (result.substr(0, 9) + ".");
    return (result);
}

void Contact::displaySummary(int index) const
{
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << formatColumn(firstName) << "|";
    std::cout << std::setw(10) << formatColumn(lastName) << "|";
    std::cout << std::setw(10) << formatColumn(nickname) << std::endl;
}

void Contact::displayContact() const
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

//ainda tem a regra de 5 funções por arquivo??