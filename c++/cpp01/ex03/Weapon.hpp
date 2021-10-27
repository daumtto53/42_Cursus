/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:39:49 by mchun             #+#    #+#             */
/*   Updated: 2021/10/27 13:56:12 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

# include <string>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon( std::string str );
		const std::string	getType( void );
		void				setType( const std::string str );
};

#endif
