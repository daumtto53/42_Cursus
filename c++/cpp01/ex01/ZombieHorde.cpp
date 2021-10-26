/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:12:03 by mchun             #+#    #+#             */
/*   Updated: 2021/10/26 22:51:21 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	if (N < 1)
		return (NULL);
	Zombie				*zombie_array = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombie_array[i].setName(name) ;
	return (zombie_array);
}

void	deleteZombieHorde(Zombie *zombie_array)
{
	delete [] zombie_array;
}
