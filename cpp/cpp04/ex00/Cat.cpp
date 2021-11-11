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
	std::cout << "Default Constructor Cat Called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Default Destructor Cat Called" << std::endl;
}

Cat::Cat(Cat const & obj)
{
	this->type = obj.type;
}

Cat & Cat::operator=(Cat const & obj)
{
	if (&obj == this)
		return *this;
	this->type = obj.type;
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
