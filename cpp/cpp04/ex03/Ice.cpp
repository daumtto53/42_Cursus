/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:16:02 by mchun             #+#    #+#             */
/*   Updated: 2021/11/16 12:29:31 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice")
{
	std::cout << "Default Constructor of Ice" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Destructor of Ice" << std::endl;
}

Ice::Ice(Ice const & obj)
	: AMateria(obj.getType())
{
	std::cout << "Copy Constructor of Ice" << std::endl;
}

Ice &	Ice::operator=(Ice const & obj)
{
	if (this == &obj)
		return (*this);
	else
		_type = std::string(obj.getType());
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter & target)
{
	std::cout << _type << " " << "shoots an ice bolt at" << target.getName() << std::endl;
}
