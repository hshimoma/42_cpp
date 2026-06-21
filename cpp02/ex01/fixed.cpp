#include "fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
	{
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{

    return this->_fixedPointValue >> _fractionalBits;
}

int Fixed::getRawBits(void) const { return this->_fixedPointValue; }
void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
