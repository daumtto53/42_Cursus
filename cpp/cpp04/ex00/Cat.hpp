/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:22:27 by mchun             #+#    #+#             */
/*   Updated: 2021/11/11 11:27:31 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

#include "Animal.hpp"

class Cat : public virtual Animal
{
private:

protected:
	std::string type;

public:
	Cat();
	Cat( Cat const & obj);
	virtual		~ Cat();
	Cat &	operator=( Cat const & obj);
	virtual void 		makeSound() const;
	virtual std::string			getType()	const;
};

#endif
