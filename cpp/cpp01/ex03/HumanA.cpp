/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:55:56 by mchun             #+#    #+#             */
/*   Updated: 2021/10/27 13:58:16 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon & weapon)
	: _weapon(weapon)
{
	_weapon = weapon;
	_name = name;
}

void	HumanA::attack( void )
{
	std::cout << _name <<  " " << "attacks with his" << " " << _weapon.getType() << std::endl;
}
