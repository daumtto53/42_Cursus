/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:22:27 by mchun             #+#    #+#             */
/*   Updated: 2021/11/11 11:03:39 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __Dog_HPP__
# define __Dog_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public virtual Animal
{
private:
	Brain	*_brain;
protected:
	std::string type;

public:
	Dog();
	Dog(Dog const & obj);
	virtual	~Dog();
	Dog &			operator=(Dog const & obj);
	virtual void 	makeSound() const;
	virtual std::string			getType()	const;
};

#endif
