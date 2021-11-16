/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:22:29 by mchun             #+#    #+#             */
/*   Updated: 2021/11/11 10:55:33 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	: type("Cat")
{
	_brain = new Brain();
	std::cout << "Default Constructor Cat Called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Default Destructor Cat Called" << std::endl;
	delete	_brain;
}

Cat::Cat(Cat const & obj)
{
	std::cout << "Copy Constructor Cat Called" << std::endl;

	int		i;
	std::string	*ideas;
	std::string	*obj_ideas;

	ideas = this->_brain->getIdeas();
	obj_ideas = obj._brain->getIdeas();

	this->type = obj.type;
	for (i = 0; i < 100; i++)
		ideas[i] = std::string(obj_ideas[i]);
}

Cat & Cat::operator=(Cat const & obj)
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

void	Cat::makeSound(void) const
{
	std::cout << "CAT MEOWS" << std::endl;
}

std::string	Cat::getType(void)	const
{
	return (this->type);
}
