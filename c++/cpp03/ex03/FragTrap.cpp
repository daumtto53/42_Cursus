/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:14:07 by mchun             #+#    #+#             */
/*   Updated: 2021/10/29 13:00:51 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap()
{
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "CREATING FragTrap" << " " << _name << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const & obj)
{
	this->_attackDamage = obj._attackDamage;
	this->_energyPoints= obj._energyPoints;
	this->_hitPoints= obj._hitPoints;
	this->_name= obj._name;
}

FragTrap::~FragTrap()
{
	std::cout << "DESTROYING FragTrap" << " " << _name << std::endl;
}

FragTrap &	FragTrap::operator=(FragTrap const & operand)
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

void	FragTrap::attack(std::string const & target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "FragTrap" << "<" << _name << ">" << "lacks ENERGY POINT" << std::endl;
		return ;
	}
	if (this->_energyPoints)
		this->_energyPoints -= 1;
	std::cout << "FragTrap" << "<" << _name << ">" \
		<< " " << "attacks" << " " << "<" << target << ">" << "," \
		<< " " << "causing" << " " << "<" << _attackDamage << ">" \
		<< " " << "points" << " " << "of" << " " << "damage!" \
		<< std::endl;
	std::cout << "Current EP : " << _energyPoints << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "FragTrap" << "<" << _name << ">" << "is already DEAD" << std::endl;
		return ;
	}
	if (this->_hitPoints < amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "FragTrap" << "<" << _name << ">" \
		<< " " << "is damaged about" << " " << amount \
		<< " " << "points" << " " << "of" << " " << "damage!" \
		<< std::endl;
	std::cout << "Current HP : " << _hitPoints << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 100)
	{
		std::cout << "FragTrap" << "<" << _name << ">" << "is already in FULL CONDITION" << std::endl;
		return ;
	}
	if ((this->_hitPoints + amount) >= 100)
		this->_hitPoints = 100;
	else
		this->_hitPoints += amount;
	std::cout << "FragTrap" << "<" << _name << ">" \
		<< " " << "is repaired" << " " << amount \
		<< " " << "points" << " " << "of" << " " << "hitPoints!" \
		<< std::endl;
	std::cout << "Current HP : " << _hitPoints << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap has entered Gate Keeper Mode" << std::endl;
}
