/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:12:40 by mchun             #+#    #+#             */
/*   Updated: 2021/10/27 20:23:15 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utility.hpp"

int		main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	else
	{
		Utility		util;
		std::string	str;
		std::string	filename(argv[1]);
		std::string	str1(argv[2]);
		std::string	str2(argv[3]);

		if (!util.readFile(filename, str))
			return (0);
		util.replaceString(str, str1, str2);
		if (!util.writeFile(filename + ".replace", str))
			return (0);
	}
	return (0);
}
