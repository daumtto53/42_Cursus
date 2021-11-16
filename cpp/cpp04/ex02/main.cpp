/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:22:31 by mchun             #+#    #+#             */
/*   Updated: 2021/11/13 13:43:45 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal	*animal_array[10];

	for (int i = 0; i < 5; i++)
	{
		std::cout << std::endl;
		animal_array[i] = new Cat();
	}
	for (int i = 5; i < 10; i++)
	{
		std::cout << std::endl;
		animal_array[i] = new Dog();
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		delete animal_array[i];
	}

	Animal	*anim = new Animal();
}
