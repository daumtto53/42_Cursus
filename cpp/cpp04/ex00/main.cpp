/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:22:31 by mchun             #+#    #+#             */
/*   Updated: 2021/11/13 13:10:34 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;

	std::cout << "-----------------" << std::endl;
	std::cout << "WRONG TEST" << std::endl << std::endl;
	const WrongAnimal *wrong = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	wrong->makeSound();
	wrongCat->makeSound();
	delete wrong;
	delete wrongCat;

	std::cout << "-------------------" << std::endl;
	std::cout << "COPY/ASSIGN TEST" << std::endl << std::endl;
	Animal src;
	Animal assignDst;
	Animal copyDst(src);

	assignDst = src;
	std::cout << std::endl;
}
