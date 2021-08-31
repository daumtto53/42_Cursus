/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:20:49 by mchun             #+#    #+#             */
/*   Updated: 2021/08/30 22:59:38 by mchun            ###   ########.fr       */
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
	REDIR_IN,
	REDIR_OUT,
	HEREDOC,
	PIPE,
	BUILT_IN,
	EXTERNAL
}	t_cmdtype;

typedef struct s_list
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
}				t_list;

typedef struct s_node
{
	enum e_cmdtype	cmdtype;
	char			**arg;
	struct s_list	*next;
}				t_node;

#endif
