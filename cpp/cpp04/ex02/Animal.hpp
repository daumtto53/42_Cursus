/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:22:27 by mchun             #+#    #+#             */
/*   Updated: 2021/11/13 13:39:10 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include <iostream>
#include <string>

class Animal
{
private:

protected:
	std::string type;

public:
	Animal();
	Animal(Animal const & obj);
	virtual			~Animal();
	Animal &		operator=(Animal const & obj);
	virtual void	makeSound() const = 0;

	virtual std::string		getType()	const;
};

#endif
