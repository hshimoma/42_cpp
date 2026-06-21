#include "harl.hpp"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void)	 { std::cout << "[ DEBUG ]\nI love having extra bacon!" << std::endl; }
void Harl::info(void)	 { std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money." << std::endl; }
void Harl::warning(void) { std::cout << "[ WARNING ]\nI think I deserve some extra bacon for free." << std::endl; }
void Harl::error(void)	 { std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl; }

void Harl::complain(std::string level)
{
	typedef void (Harl::*HarlMemFn)(void);

	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	HarlMemFn functions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	int i;

	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return ;
		}
		i++;
	}
	std::cout << "[ Unknown level ]\n* Harl mutters incomprehensibly *" << std::endl;
}
