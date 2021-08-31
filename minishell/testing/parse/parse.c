/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:20:45 by mchun             #+#    #+#             */
/*   Updated: 2021/08/31 15:54:58 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/*LINKED LIST*/
t_llist	*init_list(void)
{
	t_llist	*list;
	t_node	*dummy_node;

	list = malloc(sizeof(t_llist));
	if (!list)
		return (NULL);
	dummy_node = malloc(sizeof(t_node));
	if (!dummy_node)
		return (NULL);
	dummy_node->arg = NULL;
	dummy_node->cmdtype =  NONE;
	dummy_node->next = NULL;
	dummy_node->command_path = NULL;
	list->head = dummy_node;
	list->tail = dummy_node;
	list->size = 0;
}

int		list_push_test(t_llist *list, char *arg, t_cmdtype type)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (0);
	newnode->arg_str = arg;
	newnode->next = NULL;
	newnode->cmdtype = type;
	newnode->command_path = NULL;
	list->tail->next = newnode;
	list->tail = newnode;
	list->size++;
	return (1);
}

int		list_push(t_llist *list, char **arg, t_cmdtype type)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (0);
	newnode->arg = arg;
	newnode->next = NULL;
	newnode->command_path = NULL;
	newnode->cmdtype = type;
	list->tail->next = newnode;
	list->tail = newnode;
	list->size++;
	return (1);
}

void	list_delete(t_llist *list, t_node *delete_node)
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
