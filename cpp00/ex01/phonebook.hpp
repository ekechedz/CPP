#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void setContact(const std::string &fName, const std::string &lName,
                    const std::string &nickName, const std::string &phone,
                    const std::string &secret);

    void displayContact() const;
    void displaySummary(int index) const;
    static std::string truncate(const std::string &str);
    bool isValid() const;
};

class PhoneBook
{
private:
    Contact contacts[8]; // Can store a maximum of 8 contacts
    int contactCount;    // Tracks the number of contacts in the phonebook

public:
    PhoneBook();

    // Add a new contact to the phonebook
    void addContact();

    // Display all contacts in the SEARCH command format
    void searchContacts();
};

#endif // PHONEBOOK_HPP
