/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:04:45 by mchun             #+#    #+#             */
/*   Updated: 2021/10/27 23:06:20 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int		main()
{
	Karen person1;
	person1.complain("DEBUG");
	person1.complain("ERROR");
	person1.complain("WARNING");
	person1.complain("INFO");
}
