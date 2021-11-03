/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:26:23 by mchun             #+#    #+#             */
/*   Updated: 2021/10/23 22:34:52 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->first_name = "";
	this->last_name = "";
}

Contact::~Contact(void){}

std::string Contact::getFirst_name()
{
	return (this->first_name);
}

void Contact::setFirst_name(std::string first_name)
{
	this->first_name = first_name;
}

std::string Contact::getLast_name()
{
	return this->last_name;
}

void Contact::setLast_name(std::string last_name)
{
	this->last_name = last_name;
}

std::string Contact::getNickname()
{
	return this->nickname;
}

void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

std::string Contact::getPhone_number()
{
	return this->phone_number;
}


void Contact::setPhone_number(std::string phone_number)
{
	this->phone_number = phone_number;
}


std::string Contact::getDarkest_secret()
{
	return this->darkest_secret;
}


void Contact::setDarkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

