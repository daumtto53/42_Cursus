/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 01:30:04 by mchun             #+#    #+#             */
/*   Updated: 2021/10/29 02:14:43 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(10)
{
	std::cout << "CREATING ClapTrap" << " " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "DESTROYING ClapTrap" << " " << _name << std::endl;
}

void	ClapTrap::attack(std::string const & target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap" << "<" << _name << ">" << "lacks ENERGY POINT" << std::endl;
		return ;
	}
	if (this->_energyPoints)
		this->_energyPoints -= 1;
	std::cout << "ClapTrap" << "<" << _name << ">" \
		<< " " << "attacks" << " " << "<" << target << ">" << "," \
		<< " " << "causing" << " " << "<" << _attackDamage << ">" \
		<< " " << "points" << " " << "of" << " " << "damage!" \
		<< std::endl;
	std::cout << "Current EP : " << _energyPoints << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap" << "<" << _name << ">" << "is already DEAD" << std::endl;
		return ;
	}
	if (this->_hitPoints < amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap" << "<" << _name << ">" \
		<< " " << "is damaged about" << " " << amount \
		<< " " << "points" << " " << "of" << " " << "damage!" \
		<< std::endl;
	std::cout << "Current HP : " << _hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 10)
	{
		std::cout << "ClapTrap" << "<" << _name << ">" << "is already in FULL CONDITION" << std::endl;
		return ;
	}
	if ((this->_hitPoints + amount) >= 10)
		this->_hitPoints = 10;
	else
		this->_hitPoints += amount;
	std::cout << "ClapTrap" << "<" << _name << ">" \
		<< " " << "is repaired" << " " << amount \
		<< " " << "points" << " " << "of" << " " << "damage!" \
		<< std::endl;
	std::cout << "Current HP : " << _hitPoints << std::endl;
}
