#include "contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}


void Contact::setInformation(const std::string& fName, const std::string& lName,
							 const std::string& nName, const std::string& pNumber,
							 const std::string& dSecret)
{
	firstName = fName;
	lastName = lName;
	nickName = nName;
	phoneNumber = pNumber;
	darkestSecret = dSecret;
}

std::string Contact::getFirstName() const {return firstName; }
std::string Contact::getLastName() const {return lastName; }
std::string Contact::getNickname() const {return nickName; }
std::string Contact::getPhoneNumber() const {return phoneNumber; }
std::string Contact::getDarkestSecret() const {return darkestSecret; }