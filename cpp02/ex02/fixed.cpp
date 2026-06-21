#include "fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int intValue)
{
	this->_fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	this->_fixedPointValue = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed&::Fixed::operator=(const Fixed& other)
{
	if (this != &other) 
		this->_fixedPointValue = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {}
float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

int Fixed::getRawBits(void) const { return this->_fixedPointValue; }
void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }

bool Fixed::operator>(const Fixed& other) const { return this->_fixedPointValue > other.getRawBits(); }
bool Fixed::operator<(const Fixed& other) const { return this->_fixedPointValue < other.getRawBits(); }
bool Fixed::operator>=(const Fixed& other) const { return this->_fixedPointValue >= other.getRawBits(); }
bool Fixed::operator<=(const Fixed& other) const { return this->_fixedPointValue <= other.getRawBits(); }
bool Fixed::operator==(const Fixed& other) const { return this->_fixedPointValue == other.getRawBits(); }
bool Fixed::operator!=(const Fixed& other) const { return this->_fixedPointValue != other.getRawBits(); }

Fixed Fixed::operator+(const Fixed& other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed& other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed& other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed& other) const
{ 
    if (other.getRawBits() == 0) std::cerr << "Warning: Division by zero!" << std::endl; // 0除算対応
    return (Fixed(this->toFloat() / other.toFloat())); 
}

Fixed& Fixed::operator++(void)
{
    this->_fixedPointValue += 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_fixedPointValue += 1;
    return (temp);
}

Fixed& Fixed::operator--(void)
{
    this->_fixedPointValue -= 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_fixedPointValue -= 1;
    return (temp);
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) { return (f1 < f2) ? f1 : f2; }
const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) { return (f1 < f2) ? f1 : f2; }
Fixed& Fixed::max(Fixed& f1, Fixed& f2) { return (f1 > f2) ? f1 : f2; }
const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) { return (f1 > f2) ? f1 : f2; }

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}
