/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:22:27 by mchun             #+#    #+#             */
/*   Updated: 2021/11/13 12:05:29 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public virtual Animal
{
private:
	Brain		*_brain;

protected:
	std::string type;
public:
	Cat();
	Cat( Cat const & obj);
	virtual		~Cat();
	Cat &	operator=( Cat const & obj);
	virtual void 		makeSound() const;
	virtual std::string			getType()	const;
};

#endif
