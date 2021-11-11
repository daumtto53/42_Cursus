/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:22:27 by mchun             #+#    #+#             */
/*   Updated: 2021/11/11 11:30:41 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public virtual WrongAnimal
{
private:

protected:
	std::string type;

public:
	WrongCat();
	WrongCat( WrongCat const & obj);
	virtual		~WrongCat();
	WrongCat &	operator=( WrongCat const & obj);
	void 		makeSound() const;
	std::string	getType()	const;
};

#endif
