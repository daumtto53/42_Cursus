/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:56:44 by mchun             #+#    #+#             */
/*   Updated: 2021/10/26 22:09:39 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main()
{
	Zombie	*zombie_d = newZombie("Dynamically_allocated_zombie");
	zombie_d->announce();
	randomChump("Automatically_allocaed_zombie");
	delete zombie_d;

	return (0);
}
