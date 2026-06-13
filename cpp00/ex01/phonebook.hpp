#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void addContact();
		void searchContact();

	private:
		Contact contacts[8];
		int totalContacts;
		int oldestIndex;
		
		void printTruncated(std::string str) const;
};

#endif