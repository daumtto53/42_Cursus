/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:48:08 by mchun             #+#    #+#             */
/*   Updated: 2021/10/29 12:43:16 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

#include <string>
#include <iostream>

class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & obj);
	virtual ~ClapTrap();

	ClapTrap &	operator=(ClapTrap const & obj);
	virtual	void	attack(std::string const & target);
	virtual	void		takeDamage(unsigned int amount);
	virtual	void		beRepaired(unsigned int amount);
	void		showInfo();
};

#endif
