/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:22:56 by mchun             #+#    #+#             */
/*   Updated: 2021/10/26 21:55:46 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie( std::string name )
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << "debugging message : " << _name << " " << "DESTROYED" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << " " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
