/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 12:36:22 by mchun             #+#    #+#             */
/*   Updated: 2021/08/30 01:20:33 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../libft/libft.h"
#define ERR		0
#define SUCC	1

#define TRUE	1
#define	FALSE	0

typedef struct	s_darr
{
	char		**arr;
	int			size;
	int			capacity;
}				t_darr;

t_darr			*init_darr(char **envp);
int				env_add(t_darr *env, char *env_toadd);
int				keyval_in_env(char **arr , char *src, int size);
int				key_in_env(char **arr, char *src, int size);
int				change_env_val(char **arr, char *src, int index);
int				add_env(t_darr *env, char *src);
void			print_darr(t_darr *env);
void			delete_env(t_darr *env, char *key);
int				resize_arr(t_darr *darr);
int				keyequal_in_env(char **arr, char *src, int size);


