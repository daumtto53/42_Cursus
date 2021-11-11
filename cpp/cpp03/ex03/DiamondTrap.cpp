/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:35:46 by mchun             #+#    #+#             */
/*   Updated: 2021/11/10 22:37:54 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name")
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "CREATING DiamondTrap" << " " << _name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & obj)
{
	*this = obj;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DESTROYING DiamondTrap" << " " << _name << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & operand)
{
	if (&operand == this)
		return (*this);
	else
	{
		_hitPoints = operand._hitPoints;
		_attackDamage= operand._attackDamage;
		_energyPoints= operand._energyPoints;
		_name = operand._name;
		ClapTrap::_name = operand.ClapTrap::_name;
		return (*this);
	}
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am" << " " << _name << " " << "and also ClapTrap" << " "  << ClapTrap::_name << std::endl;
}


void	DiamondTrap::attack( std::string const & target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	FragTrap::takeDamage(amount);
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	FragTrap::beRepaired(amount);
}

void		DiamondTrap::showInfo(void)
{
	std::cout << "SHOW_INFO" << std::endl;
	std::cout << "name : " << _name << std::endl;
	std::cout << "hitPoint : " << _hitPoints << std::endl;
	std::cout << "energyPoint : " << _energyPoints << std::endl;
	std::cout << "attackDamage : " << _attackDamage << std::endl;
	std::cout << std::endl;
}
