/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:15:27 by mchun             #+#    #+#             */
/*   Updated: 2021/10/27 20:27:21 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utility.hpp"

Utility::Utility()
{
}

Utility::~Utility()
{
}


bool		Utility::readFile(std::string filename, std::string& stringbuffer)
{
	std::ifstream	inputfilestream(filename.c_str(), std::ifstream::in);
	if (!inputfilestream.is_open())
		return (false);
	std::ostringstream	oss;
	oss << inputfilestream.rdbuf();
	if (oss.fail())
	{
		inputfilestream.close();
		return (false);
	}
	stringbuffer = oss.str();
	inputfilestream.close();
	return (true);
}

void			Utility::replaceString(std::string& stringbuffer, const std::string& s1, const std::string& s2)
{
	std::size_t		index = 0;
	while (true)
	{
		index = stringbuffer.find(s1, index);
		if (index == std::string::npos)
			break;
		std::string		front = (stringbuffer.substr(0, index));
		front += s2;
		std::string		back = stringbuffer.substr(index + s1.length());
		stringbuffer = front + back;
	}
}

bool			Utility::writeFile(std::string filename, const std::string& stringbuffer)
{
	std::ofstream	outputstream(filename.c_str());
	if (!outputstream.is_open())
		return (false);

	outputstream << stringbuffer;
	outputstream.close();
	return (true);
}
