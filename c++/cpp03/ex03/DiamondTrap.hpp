/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:26:24 by mchun             #+#    #+#             */
/*   Updated: 2021/10/29 15:08:18 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:

public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const & obj);
	virtual ~DiamondTrap();

	DiamondTrap & operator=(DiamondTrap const & operand);
	void	whoAmI();
	virtual void		attack( std::string const & target );
	virtual	void		takeDamage(unsigned int amount);
	virtual	void		beRepaired(unsigned int amount);
};




#endif
