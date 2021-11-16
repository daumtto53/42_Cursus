/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:59:12 by mchun             #+#    #+#             */
/*   Updated: 2021/11/16 12:15:30 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

std::string	const & AMateria::getType() const
{
	return (_type);
}

AMateria::AMateria()
	: _type("")
{
	std::cout << "Default Constructor of AMateria" << std::endl;
}

AMateria::AMateria(std::string const & type)
	: _type(type)
{
	std::cout << "Constructor of AMateria" << std::endl;
}

AMateria::AMateria(AMateria const & obj)
	: _type(obj.getType())
{
	std::cout << "Copy Constructor of AMateria" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Destructor of AMateria" << std::endl;

}

AMateria &	AMateria::operator=(AMateria const & obj)
{
	if (&obj == this)
		return (*this);
	else
		_type = std::string(obj.getType());
	std::cout << "Assignment Operator of AMateria" << std::endl;

}
