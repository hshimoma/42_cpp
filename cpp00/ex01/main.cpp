#include "phonebook.hpp"
#include <iostream>

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Welcome to your 80s PhoneBook!" << std::endl;

	while (true)
	{
		std::cout << "Enter command (ADD, SERCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;

		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SERCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << "Goodbye! Contacts are lost forever." << std::endl;
			break;
		}
	}
	return (0);
}