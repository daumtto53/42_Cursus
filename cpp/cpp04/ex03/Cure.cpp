/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:16:02 by mchun             #+#    #+#             */
/*   Updated: 2021/11/16 12:30:52 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure")
{
	std::cout << "Default Constructor of Cure" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Destructor of Cure" << std::endl;
}

Cure::Cure(Cure const & obj)
	: AMateria(obj.getType())
{
	std::cout << "Copy Constructor of Cure" << std::endl;
}

Cure &	Cure::operator=(Cure const & obj)
{
	if (this == &obj)
		return (*this);
	else
		_type = std::string(obj.getType());
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter & target)
{
	std::cout << _type << " " << "shoots an Cure bolt at" << target.getName() << std::endl;
}
