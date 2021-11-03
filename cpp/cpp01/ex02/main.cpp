/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:28:46 by mchun             #+#    #+#             */
/*   Updated: 2021/10/27 12:38:42 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int		main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string &	stringREF = str;

	std::cout << "string's address : " << "\t" << &str << std::endl;
	std::cout << "StringPTR : " << "\t\t" << stringPTR << std::endl;
	std::cout << "StringREF : " << "\t\t" << &stringREF << std::endl;

	std::cout << "DISPLAY STRINGPTR" << " : " << *stringPTR << std::endl;
	std::cout << "DISPLAY STRINGREF" << " : " << stringREF << std::endl;

}
