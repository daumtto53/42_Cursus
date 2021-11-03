/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:56:13 by mchun             #+#    #+#             */
/*   Updated: 2021/10/27 13:56:37 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_HPP__
# define __HUMANA_HPP__

# include "Weapon.hpp"

class HumanA
{
private:
	Weapon &	_weapon;
	std::string	_name;

public:
	HumanA( std::string name, Weapon & weapon );
	void	attack( void );
};

#endif
