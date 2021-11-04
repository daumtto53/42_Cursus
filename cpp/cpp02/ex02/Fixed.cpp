/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:46:50 by mchun             #+#    #+#             */
/*   Updated: 2021/11/04 16:57:29 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	: _value(0)
{
}

Fixed::Fixed(const int input)
	: _value(input << Fixed::_fractionalBit)
{
}

Fixed::Fixed(const float input)
	: _value(static_cast<int>(roundf(input * (1 << Fixed::_fractionalBit))))
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed& fixed)
{
	_value = fixed._value;
}

Fixed&			Fixed::operator=(const Fixed& fixed)
{
	if (&fixed != this)
		this->_value = fixed.getRawBits();
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	return (_value);
}

void	Fixed::setRawBits( int const raw )
{
	_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(_value) / (1 << Fixed::_fractionalBit));
}

int		Fixed::toInt( void ) const
{
	return (_value >> Fixed::_fractionalBit);
}

std::ostream&	operator<<(std::ostream& o, const Fixed& f)
{
	return (o << f.toFloat());
}

bool	Fixed::operator>(const Fixed& fixed)
{
	return (_value > fixed.getRawBits());
}
bool	Fixed::operator<(const Fixed& fixed)
{
	return (_value < fixed.getRawBits());
}
bool	Fixed::operator>=(const Fixed& fixed)
{
	return (_value >= fixed.getRawBits());
}
bool	Fixed::operator<=(const Fixed& fixed)
{
	return (_value <= fixed.getRawBits());
}
bool	Fixed::operator==(const Fixed& fixed)
{
	return (_value == fixed.getRawBits());
}
bool	Fixed::operator!=(const Fixed& fixed)
{
	return (_value != fixed.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& fixed)
{
	Fixed	f(this->toFloat() + fixed.toFloat());
	return (f);
}
Fixed	Fixed::operator-(const Fixed& fixed)
{
	Fixed	f(this->toFloat() - fixed.toFloat());
	return (f);
}
Fixed	Fixed::operator*(const Fixed& fixed)
{
	Fixed	f(this->toFloat() * fixed.toFloat());
	return (f);
}
Fixed	Fixed::operator/(const Fixed& fixed)
{
	Fixed	f(this->toFloat() / fixed.toFloat());
	return (f);
}
Fixed	&Fixed::operator++(void)
{
	++_value;
	return (*this);
}
Fixed	&Fixed::operator--(void)
{
	--_value;
	return (*this);
}
Fixed	Fixed::operator++(int)
{
	Fixed	f(*this);

	++_value;
	return (f);
}
Fixed	Fixed::operator--(int)
{
	Fixed	f(*this);

	--_value;
	return (f);
}

Fixed	&Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed	&Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed	&Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed	&Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}
