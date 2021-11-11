/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:22:29 by mchun             #+#    #+#             */
/*   Updated: 2021/11/11 11:27:55 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	: type("Dog")
{
	std::cout << "Default Constructor Dog Called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Default Destructor Dog Called" << std::endl;
}

Dog::Dog(Dog const & obj)
{
	this->type = obj.type;
}

Dog & Dog::operator=(Dog const & obj)
{
	if (&obj == this)
		return *this;
	this->type = obj.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "DOG BARKING" << std::endl;
}

std::string	Dog::getType(void)	const
{
	return (this->type);
}
