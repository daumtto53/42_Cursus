/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:26:13 by mchun             #+#    #+#             */
/*   Updated: 2021/10/24 00:32:10 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "Contact.hpp"

#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

class PhoneBook
{
	private :
		Contact contact_list[8];
		int oldest_index;
		int toadd_index;
		int	contact_num;

	private :
		bool	is_contact_list_full(void);

	public :
		PhoneBook();
		~PhoneBook();
		void	prompt(void);
		void	add(void);

		void	print_overview(void);
		std::string	format_overview_fields(std::string str);
		void	search(void);

		void	exit(void);
		void	repeat(void);

		void	reset_console(void);

		Contact *getContact_list();
		int		getOldest_index();
		void 	setOldest_index(int oldest_index);
		int		getToadd_index();
		void 	setToadd_index(int toadd_index);
};

#endif
