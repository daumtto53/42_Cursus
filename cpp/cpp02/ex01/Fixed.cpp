/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:46:50 by mchun             #+#    #+#             */
/*   Updated: 2021/10/28 17:22:04 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int value)
{
	_value = (0xFF & value);
}

Fixed::Fixed(const float value)
{
	_value =
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
