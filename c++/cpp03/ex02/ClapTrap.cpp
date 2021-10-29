/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 01:30:04 by mchun             #+#    #+#             */
/*   Updated: 2021/10/29 12:49:02 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(10)
{
	std::cout << "CREATING ClapTrap" << " " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & obj)
{
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
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
		<< " " << "points" << " " << "of" << " " << "hitPoints!" \
		<< std::endl;
	std::cout << "Current HP : " << _hitPoints << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & operand)
{
	if (&operand == this)
		return (*this);
	else
	{
		_hitPoints = operand._attackDamage;
		_attackDamage= operand._attackDamage;
		_energyPoints= operand._energyPoints;
		_name = operand._name;
		return (*this);
	}
}

void		ClapTrap::showInfo(void)
{
	std::cout << "SHOW_INFO" << std::endl;
	std::cout << "name : " << _name << std::endl;
	std::cout << "hitPoint : " << _hitPoints << std::endl;
	std::cout << "energyPoint : " << _energyPoints << std::endl;
	std::cout << "attackDamage : " << _attackDamage << std::endl;
	std::cout << std::endl;
}
