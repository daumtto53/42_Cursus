/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:31:57 by mchun             #+#    #+#             */
/*   Updated: 2021/10/27 23:06:58 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KAREN_HPP__
# define __KAREN_HPP__

#include <string>
#include <iostream>

class Karen
{
	private:

	public:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void	complain( std::string level);

};

#endif
