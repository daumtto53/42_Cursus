/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:31:38 by mchun             #+#    #+#             */
/*   Updated: 2021/10/27 23:36:27 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void	Karen::debug( void )
{
	std::cout << "debug : " \
		<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" \
		<< std::endl;
}

void 	Karen::info( void )
{
	std::cout << "info : " << "I cannot believe adding extra bacon cost more money. " << std::endl;
}

void 	Karen::warning( void )
{
	std::cout << "warning : " << "I think I deserve to have some extra bacon for free." << std::endl;
}

void 	Karen::error( void )
{
	std::cout << "error : " << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain( std::string level )
{
	int		i;
	std::string	level_array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Karen::*karen_function[4])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

	for (i = 0; i < 4; i++)
		if (level == level_array[i])
		{
			std::cout << "[" << " " << level_array[i] << " " << "]" << std::endl;
			break;
		}

	switch (i)
	{
		case 0 :
			(this->*(karen_function[0]))();
		case 1 :
			(this->*(karen_function[1]))();
		case 2 :
			(this->*(karen_function[2]))();
		case 3 :
			(this->*(karen_function[3]))();
			break;
		case 4 :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
