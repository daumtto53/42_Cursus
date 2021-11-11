/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:22:29 by mchun             #+#    #+#             */
/*   Updated: 2021/11/11 11:11:31 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
	: type("Animal")
{
	std::cout << "Default Constructor Animal Called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Default Destructor Animal Called" << std::endl;
}

Animal::Animal(Animal const & obj)
{
	this->type = obj.type;
}

Animal & Animal::operator=(Animal const & obj)
{
	if (&obj == this)
		return *this;
	this->type = obj.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "ERROR : NO SPECIFIC TYPE" << std::endl;
}

std::string		Animal::getType()	const
{
	return (this->type);
}
