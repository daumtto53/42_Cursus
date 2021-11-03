/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:48:08 by mchun             #+#    #+#             */
/*   Updated: 2021/10/29 12:37:49 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

#include <string>
#include <iostream>

class ClapTrap
{
private:
	ClapTrap();
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
	~ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & obj);
	ClapTrap &	operator=(ClapTrap const & obj);
	void		attack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};

#endif
