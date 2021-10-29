/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 02:00:36 by mchun             #+#    #+#             */
/*   Updated: 2021/10/29 13:03:55 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int		main()
{
	ClapTrap	a("CLAP_A");
	a.showInfo();

	FragTrap	fa("SCAV_A");
	fa.showInfo();

	fa.attack("NAME:TARGET");
	{
		fa.takeDamage(1);
		fa.takeDamage(2);
		fa.takeDamage(3);
		fa.takeDamage(100);
		fa.takeDamage(100);
	}
	std::cout << std::endl;
	{
		fa.beRepaired(1);
		fa.beRepaired(2);
		fa.beRepaired(3);
		fa.beRepaired(100);
		fa.beRepaired(100);
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
