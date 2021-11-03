/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:26:26 by mchun             #+#    #+#             */
/*   Updated: 2021/10/23 22:38:31 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef __CONTACT_H__
#define __CONTACT_H__

class Contact
{
	private :
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public :
		Contact();
		~Contact();
		std::string getFirst_name();
		void		setFirst_name(std::string first_name);
		std::string getLast_name();
		void		setLast_name(std::string last_name);
		std::string getNickname();
		void		setNickname(std::string nickname);
		std::string getPhone_number();
		void		setPhone_number(std::string phone_number);
		std::string getDarkest_secret();
		void		setDarkest_secret(std::string darkest_secret);
};

#endif
