#include "phonebook.hpp"
#include <iostream>
#include <iomanip> // For formatting output
#include <limits>

// Contact class: represents a contact in the phonebook
void Contact::setContact(const std::string &fName, const std::string &lName,
                         const std::string &nickName, const std::string &phone,
                         const std::string &secret)
{
    firstName = fName;
    lastName = lName;
    nickname = nickName;
    phoneNumber = phone;
    darkestSecret = secret;
}

void Contact::displayContact() const
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void Contact::displaySummary(int index) const
{
    std::cout << "|" << std::setw(10) << std::right << index
              << "|" << std::setw(10) << std::right << truncate(firstName)
              << "|" << std::setw(10) << std::right << truncate(lastName)
              << "|" << std::setw(10) << std::right << truncate(nickname)
              << "|" << std::endl;
}

std::string Contact::truncate(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

bool Contact::isValid() const
{
    return !firstName.empty() && !lastName.empty() && !nickname.empty() &&
           !phoneNumber.empty() && !darkestSecret.empty();
}

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact()
{
    std::string fName, lName, nickName, phone, secret;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, fName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lName);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickName);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phone);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, secret);

    if (fName.empty() || lName.empty() || nickName.empty() || phone.empty() || secret.empty())
    {
        std::cout << "All fields must be filled!" << std::endl;
        return;
    }
    if (contactCount < 8)
    {
        contacts[contactCount].setContact(fName, lName, nickName, phone, secret);
        contactCount++;
    }
    else
    {
        char confirmation;
        std::cout << "Are you sure you want to replace the oldest contact? (y/n): ";
        std::cin >> confirmation;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (confirmation == 'y' || confirmation == 'Y')
        {
            std::cout << "Replacing the oldest contact..." << std::endl;
            for (int i = 1; i < 8; i++)
                contacts[i - 1] = contacts[i];
            contacts[7].setContact(fName, lName, nickName, phone, secret);
        }
        else
            std::cout << "Operation canceled. The oldest contact was not replaced." << std::endl;
    }
}

void PhoneBook::searchContacts()
{
    if (contactCount == 0)
    {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << "|" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    for (int i = 0; i < contactCount; i++)
        contacts[i].displaySummary(i + 1);
    int index;
    while (true)
    {
        std::cout << "Enter the index of the contact to display: ";

        if (std::cin >> index)
        {
            if (index >= 1 && index <= contactCount)
            {
                contacts[index - 1].displayContact();
                break;
            }
            else
                std::cout << "Invalid index! Please enter a number between 1 and " << contactCount << "." << std::endl;
        }
        else
        {
            std::cout << "Invalid input! Please enter a valid number." << std::endl;
            std::cin.clear();                                                   
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        while (command != "ADD" && command != "SEARCH" && command != "EXIT")
        {
            std::cout << "Invalid command. Enter a valid command (ADD, SEARCH, EXIT): ";
            std::getline(std::cin, command);
        }

        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContacts();
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting program..." << std::endl;
            break;
        }
    }
    return 0;
}
