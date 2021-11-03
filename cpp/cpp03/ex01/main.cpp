/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 02:00:36 by mchun             #+#    #+#             */
/*   Updated: 2021/10/29 12:50:18 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int		main()
{
	ClapTrap	a("CLAP_A");
	a.showInfo();

	ScavTrap	sa("SCAV_A");
	sa.showInfo();

	sa.attack("NAME:TARGET");
	{
		sa.takeDamage(1);
		sa.takeDamage(2);
		sa.takeDamage(3);
		sa.takeDamage(100);
		sa.takeDamage(100);
	}
	std::cout << std::endl;
	{
		sa.beRepaired(1);
		sa.beRepaired(2);
		sa.beRepaired(3);
		sa.beRepaired(100);
		sa.beRepaired(100);
	}
	std::cout << std::endl;
	a.attack("NAME:TARGET_2");
	{
		a.takeDamage(1);
		a.takeDamage(2);
		a.takeDamage(3);
		a.takeDamage(10);
		a.takeDamage(10);
	}
	std::cout << std::endl;
	{
		a.beRepaired(1);
		a.beRepaired(2);
		a.beRepaired(3);
		a.beRepaired(10);
		a.beRepaired(10);
	}
	std::cout << std::endl;
}
