/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:22:29 by mchun             #+#    #+#             */
/*   Updated: 2021/11/13 13:01:47 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	: type("Dog")
{
	this->_brain = new Brain();
	std::cout << "Default Constructor Dog Called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Default Destructor Dog Called" << std::endl;
	delete _brain;
}

Dog::Dog(Dog const & obj)
{
	std::cout << "Copy Constructor Dog Called" << std::endl;

	int		i;
	std::string	*ideas;
	std::string	*obj_ideas;

	obj_ideas = obj._brain->getIdeas();
	ideas = this->_brain->getIdeas();

	this->type = obj.type;
	for (i = 0; i < 100; i++)
		ideas[i] = std::string(obj_ideas[i]);
}

Dog & Dog::operator=(Dog const & obj)
{
	std::string	*obj_ideas;
	std::string	*ideas;

	if (&obj == this)
		return *this;
	this->type = obj.type;
	ideas = this->_brain->getIdeas();
	obj_ideas = obj._brain->getIdeas();
	for (int i = 0; i < 100; i++)
		ideas[i] = std::string(obj_ideas[i]);
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
