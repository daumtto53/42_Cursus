
#include "../includes/push_swap.h"
#include <stdio.h>
// exit() 사용하면 되므로 사용할 이유가 없어졌음.
void	free_ab_array(t_ll **ab_array)
{
	elim_linked_list(ab_array, STACK_A);
	elim_linked_list(ab_array, STACK_B);
	free(ab_array[STACK_A]);
	free(ab_array[STACK_B]);
	free(ab_array);
}

//for testing
void	traverse_list(t_ll **ab_array, int num_stack)
{
	t_ll	*list =  ab_array[num_stack];
	t_node	*node = list->tail;
	int		list_size;

	list_size = list->size;
	if (list_size == 0)
	{
		printf("empty stack\n");
		return ;
	}
	while (list_size-- > 0)
	{
		printf("%d\t", node->data);
		node = node->prev;
	}
	printf("\n");
}

void	traverse_ab(t_ll **ab_array)
{
	printf("STACK_A :\t\t");
	traverse_list(ab_array, STACK_A);
	printf("STACK_B :\t\t");
	traverse_list(ab_array, STACK_B);
}

int		count_linked_list_num(t_ll **ab_array, int num_stack)
{
	t_ll	*list = ab_array[num_stack];
	t_node	*node = list->head;
	int		count;
	int		list_size;

	list_size = list->size;
	count = 0;
	while (list_size-- > 0)
	{
		count++;
		node = node->next;
	}
	return (count);
}

void	traverse_array(int *arr, int size)
{
	int		i;

	i = 0;
	while (i < size)
		printf("%d\t", arr[i++]);
	printf("\n");
}
