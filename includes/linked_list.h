/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:24:24 by mchun             #+#    #+#             */
/*   Updated: 2021/05/26 14:49:51 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINK_LIST_H
# define LINK_LIST_H

# include <stdlib.h>
# include "../libft/libft.h"

# define STACK_A	0
# define STACK_B	1

typedef struct s_node
{
	int		data;
	t_node	*prev;
	t_node	*next;
}				t_node;

typedef struct	s_ll
{
	t_node	*tail;
	t_node	*head;
	int		size;
}				t_ll;

#endif
