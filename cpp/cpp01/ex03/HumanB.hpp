/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:29:02 by mchun             #+#    #+#             */
/*   Updated: 2021/10/27 13:57:38 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

# include "Weapon.hpp"

class HumanB
{
private:
	Weapon	*_weapon;
	std::string	_name;

public:
	HumanB( std::string name );
	void	attack( void );
	Weapon &	getWeapon( void );
	void		setWeapon( Weapon & weapon );
};

#endif
