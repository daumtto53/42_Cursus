/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:26:34 by mchun             #+#    #+#             */
/*   Updated: 2021/10/24 13:59:15 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->oldest_index = 0;
	this->toadd_index = 0;
	this->contact_num = 0;
}

PhoneBook::~PhoneBook(){}

void	PhoneBook::prompt(void)
{
	std::cout << "-------    PHONEBOOK    ----------" << std::endl << std::endl;
	std::cout << "Enter ADD, SEARCH, EXIT" << std::endl;
	std::cout << std::endl;
	std::cout << "INPUT : ";
}

void	PhoneBook::add(void)
{
	std::string		user_input;
	std::string		first_name;
	std::string		last_name;
	Contact			*list;

	reset_console();
	list = &(contact_list[oldest_index]);
	std::cout << "ENTER EACH FIELDS" << std::endl;
	std::cout << std::endl;

	std::cout << "ENTER FIRST NAME" << std::endl;
	getline(std::cin, first_name);

	std::cout << "ENTER LAST NAME" << std::endl;
	getline(std::cin, last_name);

	if (first_name.empty() && last_name.empty())
	{
		reset_console();
		std::cout << "!!!!!!!!!! EMPTY FIELDS" << std::endl;
		return ;
	}

	list->setFirst_name(first_name);
	list->setLast_name(last_name);


	std::cout << "ENTER NICKNAME" << std::endl;
	getline(std::cin, user_input);
	list->setNickname(user_input);

	std::cout << "ENTER PHONE_NUMBER" << std::endl;
	getline(std::cin, user_input);
	list->setPhone_number(user_input);

	std::cout << "ENTER DARKEST SECRET" << std::endl;
	getline(std::cin, user_input);
	list->setDarkest_secret(user_input);


	oldest_index = (oldest_index + 1) % 8;
	if (contact_num <= 7)
		contact_num++;
	return ;

}

void	PhoneBook::print_overview(void)
{
	Contact		*list;
	int		i;

	reset_console();
	list = contact_list;
	std::cout << "----------OVERVIEW----------" << std::endl;
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "first name";
	std::cout << "|" << std::setw(10) << "last name";
	std::cout << "|" << std::setw(10) << "nickname";
	std::cout << "|" << std::endl;
	std::cout << "----------------------------" << std::endl;

	for (i = 0; i < 8; i++)
	{
		if (list[i].getFirst_name().empty() && list[i].getLast_name().empty())
			continue;
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) <<  format_overview_fields(list[i].getFirst_name());
		std::cout << "|" << std::setw(10) <<  format_overview_fields(list[i].getLast_name());
		std::cout << "|" << std::setw(10) <<  format_overview_fields(list[i].getNickname());
		std::cout << "|" << std:: endl;
	}
}

std::string	PhoneBook::format_overview_fields(std::string str)
{
	if (str.length() < 10)
		return (str.substr(0, str.length()));
	else
		return (str.substr(0, 9).append("."));
}

bool	PhoneBook::is_invalid_search_input(int user_input_num)
{
	if (std::cin.fail() || user_input_num >= contact_num || user_input_num < 0)
	{
		if (std::cin.fail())
			std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "!!!!!!!!!!!! Invalid Index " << std::endl << std::endl;
		return (true);
	}
	return (false);
}

void	PhoneBook::search(void)
{
	int		user_input_num;
	Contact		*list;

	list = contact_list;

	reset_console();
	print_overview();
	std::cout << "INPUT Index Num To Search" << std::endl;
	std::cin >> user_input_num;
	if (is_invalid_search_input(user_input_num))
		return;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "------------show selected database-------------" << std::endl;
	std::cout << "First Name : " << list[user_input_num].getFirst_name() << std::endl;
	std::cout << "Last Name : " << list[user_input_num].getLast_name() << std::endl;
	std::cout << "NickName : " << list[user_input_num].getNickname() << std::endl;
	std::cout << "PhoneNumber : " << list[user_input_num].getPhone_number() << std::endl;
	std::cout << "Darkest Secret : " << list[user_input_num].getDarkest_secret() << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
}

void	PhoneBook::exit(void)
{
	reset_console();
	std::cout << std::endl;
	std::cout << "Exiting PhoneBook....." << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::repeat(void)
{
	reset_console();
	std::cout << "!!!!!!! Invalid Command....... Enter Wisely." << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::reset_console(void)
{
	for(int i = 0; i < 20; i++)
		std::cout << std::endl;
}



Contact	*PhoneBook::getContact_list()
{
	return this->contact_list;
}

int		PhoneBook::getOldest_index()
{
	return this->oldest_index;
}

void 	PhoneBook::setOldest_index(int oldest_index)
{
	this->oldest_index = oldest_index;
}

int		PhoneBook::getToadd_index()
{
	return this->toadd_index;
}

void 	PhoneBook::setToadd_index(int toadd_index)
{
	this->toadd_index = toadd_index;
}
