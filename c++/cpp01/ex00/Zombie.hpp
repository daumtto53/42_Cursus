/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:23:11 by mchun             #+#    #+#             */
/*   Updated: 2021/10/26 21:51:11 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class	Zombie
{
	private:
		std::string	_name;

	public:
		Zombie();
		Zombie( std::string name );
		~Zombie();
		void	announce(void);
};

Zombie* newZombie( std::string name );

void randomChump( std::string name );
