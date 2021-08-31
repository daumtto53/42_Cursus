/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:33:35 by mchun             #+#    #+#             */
/*   Updated: 2021/08/31 11:40:58 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

// int		count_args(char *str)
// {
// 	int		i;
// 	int		arg_num;

// 	arg_num = 0;

// 	i = -1;
// 	while (str[++i] != '\0')
// 	{



// 	}

// }

// char	**arg_split(char *str)
// {
// 	//쪼갤 문자열의 개수
// 	//쪼갠 문자열을 넣을 char **배열 동적할당
// 	//문자열을 넣어주고

// }

void	**arg_split(char *input)
{
	int		begin;
	int		cur;
	int		in_quote;

	begin = 0;
	cur = 0;
	in_quote = 0;
	int		i = 0;
	while (1)
	{
		if (input[cur] == '\"' || input[cur] == '\'')
			in_quote++;
		if (input[cur] == '|' && in_quote % 2 == 0)
		{
			printf("%s\n", strndup(input + begin, cur - begin + 1 - 1));
			printf("%s\n", strndup(input + cur, 1));
			begin = cur + 1;
		}
		else if ((input[cur] == '>' || input[cur] == '<') && in_quote % 2 == 0)
		{
			printf("%s\n", strndup(input + begin,  cur - begin + 1 - 1));
			i = 1;
			while (((input + cur)[i] != '>' && (input + cur)[i] != '|' & (input + cur)[i] != '<' && (input + cur)[i] != '\0') || in_quote % 2 == 1)
			{
				if ((input + cur)[i] == '\"' || (input + cur)[i] == '\'')
					in_quote++;
				i++;
			}
			printf("%s\n", strndup(input + cur, i));
			begin = cur + i;
			cur = cur + i - 1;
		}
		else if (input[cur] == '\0')
		{
			printf("%s", strndup(input + begin, cur - begin + 1 - 1));
			break;
		}
		cur++;
	}
}

/* arg split에서 linked_list에 type을 구분해서 char **를 넣어준 다음, 모든 parsing이 끝났다고 간주한다. */
/* parsing이 끝난 이후에 node의 arg에서 variable expansion을 진행한다.*/

int		main(int argc, char **argv)
{
	char	**splited_arg;
	char	*line_read;

	line_read = readline("$");
	arg_split(line_read);
	return (0);
}
