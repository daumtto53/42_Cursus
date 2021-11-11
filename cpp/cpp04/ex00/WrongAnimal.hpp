/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:22:27 by mchun             #+#    #+#             */
/*   Updated: 2021/11/11 11:24:00 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

#include <iostream>

class WrongAnimal
{
private:

protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const & obj);
	virtual			~WrongAnimal();
	WrongAnimal &		operator=(WrongAnimal const & obj);
	void	makeSound() const;

	std::string		getType()	const;
};

#endif
