/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:54:30 by mchun             #+#    #+#             */
/*   Updated: 2021/11/13 12:49:13 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	this->ideas = new std::string[100];
	std::cout << "Default Constructior Brain Called" << std::endl;
}

Brain::~Brain()
{
	delete [](this->ideas);
	std::cout << "Default Destructor Brain Called" << std::endl;
}

Brain::Brain(Brain const & obj)
{
	int		i;

	std::cout << "Copy Constructor Brain Called" << std::endl;
	for (i = 0; i < 100; i++)
		this->ideas[i] = std::string(obj.ideas[i]);
}

Brain & Brain::operator=(Brain const & obj)
{
	int		i;

	if (&obj == this)
		return (*this);
	else
	{
		for (i = 0; i < 100; i++)
			this->ideas[i] = std::string(obj.ideas[i]);
		return (*this);
	}
}

std::string		*Brain::getIdeas(void)
{
	return (this->ideas);
}
