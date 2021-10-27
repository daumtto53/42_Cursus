/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:39:34 by mchun             #+#    #+#             */
/*   Updated: 2021/10/27 13:49:48 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	this->type = type;
}


const std::string	Weapon::getType( void )
{
	return (this->type);
}
void				Weapon::setType( const std::string type )
{
	this->type = type;
}
