/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:33:35 by mchun             #+#    #+#             */
/*   Updated: 2021/08/31 17:46:12 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "parse.h"


/* from this */
int		parse_redirect(char *input, t_llist *list, int begin)
{
	int		cur;
	t_cmdtype	type;

	if (input[begin] == '<')
		type = REDIR_IN;
	else
		type = REDIR_OUT;
	cur = begin + 1;
	while (input[cur] != '>' && input[cur] != '<' && input[cur] != '|' && input[cur] != '\0')
	{
		if (input[cur] == '\"' || input[cur] == '\'')
		{
			if (input[cur] == '\"')
				while (input[cur] == '\"')
					cur++;
			else
				while (input[cur] == '\'')
					cur++;
		}
		else
			cur++;
	}
	printf("%s\n", strndup(input + begin, cur - begin));	//split_args
	list_push_test(list, strndup(input + begin, cur - begin), REDIR_OUT);
	return (cur);
}

int		parse_pipe(char *input, t_llist *list, int begin)
{
	int		cur;
	t_cmdtype	type;

	printf("%s\n", strndup(input + begin, 1));
	list_push_test(list , strndup(input + begin, 1), PIPE);
	begin = begin + 1;
	return (begin + 1);
}

int		parse_command(char *input, t_llist *list, int begin)
{
	int		cur;

	cur = begin;
	while (input[cur] != '>' && input[cur] != '<' && input[cur] != '|' && input[cur] != '\0')
	{
		if (input[cur] == '\"' || input[cur] == '\'')
		{
			if (input[cur] == '\"')
				while (input[cur] == '\"')
					cur++;
			else
				while (input[cur] == '\'')
					cur++;
		}
		else
			cur++;
	}
	printf("%s\n", strndup(input + begin, cur - begin));
	list_push_test(list, strndup(input + begin, cur - begin), COMMAND);
	begin = cur;
	return (begin);
}

/* to this */
void	arg_split_4(char *input, t_llist *list)
{
	int		begin;
	int		cur;

	begin = cur = 0;
	while (input[begin] != '\0')
	{
		while (input[begin] == ' ')
			begin++;
		if (input[begin] == '>' || input[begin] == '<')
		{
			begin = parse_redirect(input, list , begin);
		}
		else if (input[begin] == '|')
		{
			begin = parse_pipe(input, list ,begin);
		}
		else
		{
			begin = parse_command(input, list, begin);
		}
	}
}

int		argv_split(t_llist *list)
{
	t_node	*node;
	char	**temp_argv;

	node = list->head->next;
	while (!node)
	{
		temp_argv = ft_split_equal(node->arg_str, ' ');
		if (!temp_argv)
			return (0);
	}
}

void	arg_split_3(char *input)
{
	int		begin;
	int		cur;

	begin = cur = 0;
	while (input[begin] != '\0')
	{
		while (input[begin] == ' ')
			begin++;
		if (input[begin] == '>' || input[begin] == '<')
		{
			cur = begin + 1;
			while ((input[cur] != '>' && input[cur] != '<' && input[cur] != '|')  && input[cur] != '\0')
			{
				if (input[cur] == '\"' || input[cur] == '\'')
				{
					if (input[cur] == '\"')
						while (input[cur] == '\"')
							cur++;
					else
						while (input[cur] == '\'')
							cur++;
				}
				else
					cur++;
			}
			printf("%s\n", strndup(input + begin, cur - begin));
			begin = cur;
		}
		else if (input[begin] == '|')
		{
			printf("%s\n", strndup(input + begin, 1));
			begin = begin + 1;
		}
		else
		{
			cur = begin;
			while ((input[cur] != '>' && input[cur] != '<' && input[cur] != '|')  && input[cur] != '\0')
			{
				if (input[cur] == '\"' || input[cur] == '\'')
				{
					if (input[cur] == '\"')
						while (input[cur] == '\"')
							cur++;
					else
						while (input[cur] == '\'')
							cur++;
				}
				else
					cur++;
			}
			printf("%s\n", strndup(input + begin, cur - begin));
			begin = cur;
		}
	}
}

void	arg_split_2(char *input)
{
	int		begin;
	int		cur;
	int		single_q = 0;
	int		double_q = 0;

	begin = cur = single_q = double_q = 0;
	while (input[begin] != '\0')
	{
		while (input[begin] == ' ')
			begin++;
		if ((input[begin] == '>' || input[begin] == '<') && (double_q % 2 == 0 && single_q % 2 == 0))
		{
			cur = begin + 1;
			while (((input[cur] != '>' && input[cur] != '<' && input[cur] != '|') || (single_q % 2 == 1 || double_q % 2 == 1)) && input[cur] != '\0')
			{
				if (input[cur] == '\"' || input[cur] == '\'')
				{
					if (input[cur] == '\"')
						double_q++;
					else
						single_q++;
				}
				cur++;
			}
			printf("%s\n", strndup(input + begin, cur - begin));
			begin = cur;
		}
		else if (input[begin] == '|')
		{
			printf("%s\n", strndup(input + begin, 1));
			begin = begin + 1;
		}
		else
		{
			cur = begin;
			while (((input[cur] != '>' && input[cur] != '<' && input[cur] != '|') || (single_q % 2 == 1 || double_q % 2 == 1)) && input[cur] != '\0')
			{
				if (input[cur] == '\"' || input[cur] == '\'')
				{
					if (input[cur] == '\"')
						double_q++;
					else
						single_q++;
				}
				cur++;
			}
			printf("%s\n", strndup(input + begin, cur - begin));
			begin = cur;
		}
	}
}

/* arg split에서 linked_list에 type을 구분해서 char **를 넣어준 다음, 모든 parsing이 끝났다고 간주한다. */
/* parsing이 끝난 이후에 node의 arg에서 variable expansion을 진행한다.*/


int		main(int argc, char **argv)
{
	char	**splited_arg;
	char	*line_read;
	t_llist	*list;

	list = init_list();

	line_read = readline("$");
	// arg_split(line_read);
	arg_split_4(line_read, list);
	argv_split(list);
	return (0);
}
