/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:28:54 by mchun             #+#    #+#             */
/*   Updated: 2021/10/27 13:58:30 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	_name = name;
}

void	HumanB::attack( void )
{
	std::cout << _name << " " << "attacks with his" << " " << getWeapon().getType() << std::endl;
}

Weapon &	HumanB::getWeapon( void )
{
	return *(_weapon);
}

void		HumanB::setWeapon( Weapon & weapon )
{
	_weapon = &weapon;
}
