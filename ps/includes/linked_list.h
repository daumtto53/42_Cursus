/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:24:24 by mchun             #+#    #+#             */
/*   Updated: 2021/06/02 21:27:24 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>
# include "../libft/libft.h"

# define STACK_A	0
# define STACK_B	1

typedef struct	s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct	s_ll
{
	t_node	*tail;
	t_node	*head;
	int		size;
}				t_ll;

int				init_linked_list(t_ll ***ab_arr);
int				linked_list_push(t_ll **ab_arr, int	num_stack, int data);
int				linked_list_pop(t_ll **ab_arr, int num_stack, int *data);
void			elim_linked_list(t_ll **ab_arr, int num_stack);

void			free_ab_array(t_ll **ab_array);
int				count_linked_list_num(t_ll **ab_array, int num_stack);

#endif
