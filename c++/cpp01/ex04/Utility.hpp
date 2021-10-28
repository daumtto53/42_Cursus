/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:08:20 by mchun             #+#    #+#             */
/*   Updated: 2021/10/27 19:10:04 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILITY_HPP__
# define __UTILITY_HPP__

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class Utility
{
private:

public:
	Utility();
	~Utility();

	static bool		readFile(std::string filename, std::string& stringbuffer);
	static void		replaceString(std::string& stringbuffer, const std::string& s1, const std::string& s2);
	static bool		writeFile(std::string filename, const std::string& stringbuffer);
};



#endif
