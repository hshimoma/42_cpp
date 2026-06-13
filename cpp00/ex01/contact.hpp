#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	public:
		Contact();
		~Contact();

		void setInformation(const std::string& fName, const std::string& lName,
							const std::string& nName, const std::string& pNumber,
							const std::string& dSecret);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;

	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif