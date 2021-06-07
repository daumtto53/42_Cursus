/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:42:59 by mchun             #+#    #+#             */
/*   Updated: 2021/06/07 22:21:09 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

# define	PARENT_INDEX	0
# define	CHILD_INDEX		1

typedef struct	s_parsed
{
	const char	*file;
	const char	*cmd;
	char const	**argv;
	char const	**envp;
	char		*cmd_path;
}				t_parsed;

#endif
