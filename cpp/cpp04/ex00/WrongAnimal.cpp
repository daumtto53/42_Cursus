/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:22:29 by mchun             #+#    #+#             */
/*   Updated: 2021/11/11 11:11:31 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("WrongAnimal")
{
	std::cout << "Default Constructor WrongAnimal Called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Default Destructor WrongAnimal Called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & obj)
{
	std::cout << "Copy Constructor WrongAnimal Called" << std::endl;
	this->type = obj.type;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & obj)
{
	if (&obj == this)
		return *this;
	this->type = obj.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "ERROR : NO SPECIFIC TYPE" << std::endl;
}

std::string		WrongAnimal::getType()	const
{
	return (this->type);
}
