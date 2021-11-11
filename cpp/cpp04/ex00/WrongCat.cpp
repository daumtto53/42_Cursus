/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:22:29 by mchun             #+#    #+#             */
/*   Updated: 2021/11/11 10:55:33 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
	: type("WrongCat")
{
	std::cout << "Default Constructor WrongCat Called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Default Destructor WrongCat Called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & obj)
{
	this->type = obj.type;
}

WrongCat & WrongCat::operator=(WrongCat const & obj)
{
	if (&obj == this)
		return *this;
	this->type = obj.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat MEOWS" << std::endl;
}
