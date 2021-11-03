/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:26:20 by mchun             #+#    #+#             */
/*   Updated: 2021/10/23 21:26:21 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
	std::string basic_output = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (argc == 1)
		std::cout << basic_output << std::endl;
	else
	{
		int		i, j;

		for (j = 1; argv[j]; j++)
		{
			for (i = 0 ; argv[j][i]; i++)
				std::cout << static_cast<char>(std::toupper(argv[j][i]));
		}
		std::cout << std::endl;
	}
	return (0);
}
