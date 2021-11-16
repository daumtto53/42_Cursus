/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:52:14 by mchun             #+#    #+#             */
/*   Updated: 2021/11/16 11:58:16 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
# define __CURE_HPP__

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(std::string type);
	Cure(Cure const & obj);
	~Cure();

	Cure &	operator=(Cure const & obj);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
