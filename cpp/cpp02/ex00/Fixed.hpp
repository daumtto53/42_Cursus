/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:46:52 by mchun             #+#    #+#             */
/*   Updated: 2021/11/03 20:26:32 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>

class Fixed
{
private:
	int					_value;
	static const int	_word = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& fixed);

	Fixed	&operator=(const Fixed& fixed);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif
