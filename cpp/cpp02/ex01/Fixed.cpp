/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:46:50 by mchun             #+#    #+#             */
/*   Updated: 2021/11/04 15:06:31 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	: _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int input)
	: _value(input << Fixed::_fractionalBit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float input)
	: _value(static_cast<int>(roundf(input * (1 << Fixed::_fractionalBit))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = fixed._value;
}

Fixed&			Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	if (&fixed != this)
		this->_value = fixed.getRawBits();
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;

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
