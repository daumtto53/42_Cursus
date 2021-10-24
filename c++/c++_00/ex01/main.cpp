/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:26:28 by mchun             #+#    #+#             */
/*   Updated: 2021/10/24 11:38:55 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

		#include <unistd.h>

int		main(void)
{
	PhoneBook	phonebook;
	std::string	user_input;

	while (1)
	{
		phonebook.prompt();
		getline(std::cin, user_input);
		std::cout << "USER TEST : " << user_input << std::endl;
			sleep(1);		//
		if (user_input.compare("ADD") == 0)
			phonebook.add();
		else if (user_input.compare("SEARCH") == 0)
			phonebook.search();
		else if (user_input.compare("EXIT") == 0)
		{
			phonebook.exit();
			break;
		}
		else
			phonebook.repeat();
	}
	return (0);
}
