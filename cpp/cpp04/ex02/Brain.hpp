/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:54:36 by mchun             #+#    #+#             */
/*   Updated: 2021/11/12 18:26:53 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <string>
# include <iostream>

class Brain
{
private:
	std::string	*ideas;

protected:

public:
	Brain();
	~Brain();
	Brain(Brain const & obj);
	Brain & operator=(Brain const & obj);
	std::string		*getIdeas(void);
};

#endif
