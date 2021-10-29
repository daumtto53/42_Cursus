/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:14:05 by mchun             #+#    #+#             */
/*   Updated: 2021/10/29 14:28:52 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

# include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
private:

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const & obj);
	virtual ~FragTrap();

	FragTrap & operator=(FragTrap const & operand);
	virtual void	attack(std::string const & target);
	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);
	void			highFivesGuys(void);
};

#endif
