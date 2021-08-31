/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:20:49 by mchun             #+#    #+#             */
/*   Updated: 2021/08/31 18:13:15 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <stdlib.h>
# include "../../../libft/libft.h"

typedef enum e_cmdtype
{
	NONE,
	COMMAND,
	REDIR_IN,
	REDIR_OUT,
	REDIR_ERR,
	HEREDOC,
	PIPE,
	BUILT_IN,
	EXTERNAL
}	t_cmdtype;

typedef struct s_llist
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
}				t_llist;

typedef struct s_node
{
	enum e_cmdtype	cmdtype;
	char			*arg_str;
	char			*command_path;
	char			**arg;
	struct s_node	*next;
}				t_node;

t_llist	*init_list(void);
int		list_push(t_llist *list, char **arg, t_cmdtype type);
void	list_delete(t_llist *list, t_node *delete_node);
int		list_push_test(t_llist *list, char *arg, t_cmdtype type);

#endif
