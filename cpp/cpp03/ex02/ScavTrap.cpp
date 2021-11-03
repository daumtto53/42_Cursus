/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:14:07 by mchun             #+#    #+#             */
/*   Updated: 2021/10/29 12:59:43 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap()
{
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "CREATING ScavTrap" << " " << _name << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & obj)
{
	this->_attackDamage = obj._attackDamage;
	this->_energyPoints= obj._energyPoints;
	this->_hitPoints= obj._hitPoints;
	this->_name= obj._name;
}

ScavTrap::~ScavTrap()
{
	std::cout << "DESTROYING ScavTrap" << " " << _name << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & operand)
{
	if (&operand == this)
		return (*this);
	else
	{
		this->_attackDamage = operand._attackDamage;
		this->_energyPoints= operand._energyPoints;
		this->_hitPoints = operand._hitPoints;
		this->_name= operand._name;
		return (*this);
	}
}

void	ScavTrap::attack(std::string const & target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap" << "<" << _name << ">" << "lacks ENERGY POINT" << std::endl;
		return ;
	}
	if (this->_energyPoints)
		this->_energyPoints -= 1;
	std::cout << "ScavTrap" << "<" << _name << ">" \
		<< " " << "attacks" << " " << "<" << target << ">" << "," \
		<< " " << "causing" << " " << "<" << _attackDamage << ">" \
		<< " " << "points" << " " << "of" << " " << "damage!" \
		<< std::endl;
	std::cout << "Current EP : " << _energyPoints << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap" << "<" << _name << ">" << "is already DEAD" << std::endl;
		return ;
	}
	if (this->_hitPoints < amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ScavTrap" << "<" << _name << ">" \
		<< " " << "is damaged about" << " " << amount \
		<< " " << "points" << " " << "of" << " " << "damage!" \
		<< std::endl;
	std::cout << "Current HP : " << _hitPoints << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 100)
	{
		std::cout << "ScavTrap" << "<" << _name << ">" << "is already in FULL CONDITION" << std::endl;
		return ;
	}
	if ((this->_hitPoints + amount) >= 100)
		this->_hitPoints = 100;
	else
		this->_hitPoints += amount;
	std::cout << "ScavTrap" << "<" << _name << ">" \
		<< " " << "is repaired" << " " << amount \
		<< " " << "points" << " " << "of" << " " << "hitPoints!" \
		<< std::endl;
	std::cout << "Current HP : " << _hitPoints << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap has entered Gate Keeper Mode" << std::endl;
}
