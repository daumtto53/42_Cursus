/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:20:45 by mchun             #+#    #+#             */
/*   Updated: 2021/08/30 23:18:09 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"




/*LINKED LIST*/
t_list	*init_list(void)
{
	t_list	*list;
	t_node	*dummy_node;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	dummy_node = malloc(sizeof(t_node));
	if (!dummy_node)
		return (NULL);
	dummy_node->arg = NULL;
	dummy_node->cmdtype =  NONE;
	dummy_node->next = NULL;
	list->head = dummy_node;
	list->tail = dummy_node;
	list->size = 0;
}

int		*list_push(t_list *list, char **arg, t_cmdtype type)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (0);
	newnode->arg = arg;
	newnode->next = NULL;
	newnode->cmdtype = type;
	list->tail->next = newnode;
	list->tail = newnode;
	list->size++;
}

void	list_delete(t_list *list, t_node *delete_node)
{
	t_node	*curr_node;

	curr_node = list->head->next;
	while (curr_node)
	{
		if (curr_node == delete_node)
		{
			// free_splited_arg(curr_node->arg);
			free(curr_node);
			break;
		}
	}
}
