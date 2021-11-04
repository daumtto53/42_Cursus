/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:46:52 by mchun             #+#    #+#             */
/*   Updated: 2021/11/04 16:55:54 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <cmath>
#include <iostream>

class Fixed
{
private:
	int					_value;
	static const int	_fractionalBit = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& fixed);

	Fixed	&operator=(const Fixed& fixed);

	bool	operator>(const Fixed& fixed);
	bool	operator<(const Fixed& fixed);
	bool	operator>=(const Fixed& fixed);
	bool	operator<=(const Fixed& fixed);
	bool	operator==(const Fixed& fixed);
	bool	operator!=(const Fixed& fixed);

	Fixed	operator+(const Fixed& fixed);
	Fixed	operator-(const Fixed& fixed);
	Fixed	operator*(const Fixed& fixed);
	Fixed	operator/(const Fixed& fixed);

	Fixed		&operator++(void);
	Fixed		&operator--(void);
	Fixed		operator++(int);
	Fixed		operator--(int);

	static Fixed	&min(Fixed& f1, Fixed& f2);
	static Fixed	&max(Fixed& f1, Fixed& f2);
	static const Fixed	&min(const Fixed& f1, const Fixed& f2);
	static const Fixed	&max(const Fixed& f1, const Fixed& f2);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream& o, const Fixed& f);

#endif
