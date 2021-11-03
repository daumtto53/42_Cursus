/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:56:44 by mchun             #+#    #+#             */
/*   Updated: 2021/10/26 22:54:18 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main()
{
	int		zombie_num = 10;

	std::cout << "Creating" << " "  << zombie_num << std::endl;
	Zombie	*zombie_arr = zombieHorde(zombie_num, "Random Name of Horde of Zombies");

	for(int i = 0; i < zombie_num; i++)
	{	std::cout << i << " : ";
		zombie_arr[i].announce();
	}
	std::cout << "Destroying" << " "  << zombie_num << std::endl;
	delete [] zombie_arr;
	return (0);
}
