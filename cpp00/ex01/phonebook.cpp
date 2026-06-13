#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() : totalContacts(0), oldestIndex(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact()
{
	std::string fName, lName, nName, pNumber, dSecret;

	std::cout << "---New Contact ---" << std::endl;

	while (fName.empty()) { std::cout << "First Name: "; std::getline(std::cin, fName); }
	while (lName.empty()) { std::cout << "Last Name: "; std::getline(std::cin, lName); }
	while (nName.empty()) { std::cout << "Nickname: "; std::getline(std::cin, nName); }
	while (pNumber.empty()) {std::cout << "Phone Number: "; std::getline(std::cin, pNumber); }
	while (dSecret.empty()) { std::cout << "Darkest Secret: "; std::getline(std::cin, dSecret); }

	contacts[oldestIndex].setInformation(fName, lName, nName, pNumber, dSecret);

	oldestIndex = (oldestIndex + 1) % 8;
	if (totalContacts < 8)
		totalContacts++;

	std::cout << "Contact successfully added!" << std::endl;
}

void PhoneBook::printTruncated(std::string str) const
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

void PhoneBook::searchContact()
{
	if (totalContacts == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "   Index| First Name| Last Name| Nickname|   " << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	int i;

	i = 0;
	while (i < totalContacts)
	{
		std::cout << std::setw(10) << i << "|";
		printTruncated(contacts[i].getFirstName()); std::cout << "|";
		printTruncated(contacts[i].getLastName()); std::cout << "|";
		printTruncated(contacts[i].getNickname()); std::cout << "|";
		std::cout << std::endl;
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl;

	std::string input;
	std::cout << "Enter Index to display details: ";
	std::getline(std::cin, input);

	if (input.length() == 1 && input[0] >= '0' && input[0] < '0' + totalContacts)
	{
		int index = input[0] - '0';
		std:: cout << "First Name: " << contacts[index].getFirstName() << std::endl;
		std:: cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std:: cout << "Nickname: " << contacts[index].getNickname() << std::endl;
		std:: cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
		std:: cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	}
	else
		std:: cout << "Invalid index!" << std::endl;
}