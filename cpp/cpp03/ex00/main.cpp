/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 02:00:36 by mchun             #+#    #+#             */
/*   Updated: 2021/10/29 02:03:46 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int		main()
{
	ClapTrap	a("A");
	ClapTrap	b("B");

	a.attack("NAME:TARGET");

	{
		a.takeDamage(1);
		a.takeDamage(2);
		a.takeDamage(3);
		a.takeDamage(10);
		a.takeDamage(10);
	}

	{
		a.beRepaired(1);
		a.beRepaired(2);
		a.beRepaired(3);
		a.beRepaired(10);
		a.beRepaired(10);
	}
}
