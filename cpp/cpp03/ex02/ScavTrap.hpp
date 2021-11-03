/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:14:05 by mchun             #+#    #+#             */
/*   Updated: 2021/10/29 12:59:41 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	ScavTrap();

public:
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & obj);
	virtual ~ScavTrap();

	ScavTrap & operator=(ScavTrap const & operand);
	virtual void	attack(std::string const & target);
	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);
	void			guardGate();
};

#endif
