#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";

	std::string* stringSTR = &str;

	std::string& stringREF = str;

	std::cout << "--- Addresses ---" << std::endl;
	std::cout << "Address of str:       " << &str << std::endl;
	std::cout << "Address in stringSTR: " << stringSTR << std::endl;
	std::cout << "Address in stringREF: " << &stringREF << std::endl;

	std::cout << "--- Values ---" << std::endl;
	std::cout << "Value of str:        " << str << std::endl;
	std::cout << "Value in stringSTR:   " << *stringSTR << std::endl;
	std::cout << "Value in stringREF:   " << stringREF << std::endl;

	return (0);
}
