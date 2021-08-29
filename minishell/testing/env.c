/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 13:00:06 by mchun             #+#    #+#             */
/*   Updated: 2021/08/30 01:20:15 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//동적 배열로 만들어놓고.. keep track of size
#include "./env.h"

t_darr		*init_darr(char **envp)
{
	int		i;
	t_darr	*env;

	env = (t_darr *)malloc(sizeof(t_darr));
	i = -1;
	while (envp[++i])
		env->size = i;
	env->capacity = i;
	printf("%d\n", i);
	env->arr = (char **)malloc(sizeof(char *) * i);
	if (!env->arr)
		return (ERR);
	i = -1;
	while (++i < env->size)
		env->arr[i] = ft_strdup(envp[i]);
	return (env);
}

int				env_add(t_darr *env, char *env_toadd)
{
	int		keyptr;

	//이미 존재하는 환경변수는
	if (keyval_in_env(env->arr, env_toadd, env->size))
		return (SUCC);
	keyptr = keyequal_in_env(env->arr, env_toadd, env->size);
	if (keyptr > 0)
	{
		change_env_val(env->arr, env_toadd, keyptr);
		return (SUCC);
	}
	else
		add_env(env, env_toadd);
	return (SUCC);
}

int				keyval_in_env(char **arr , char *src, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		if (strcmp(arr[i], src) == 0)		//strcmp를 libft에 만들어야함.
			return (TRUE);
	return (FALSE);
}

// leaks : def lost
int				keyequal_in_env(char **arr, char *src, int size)
{
	int		i;
	int		j;
	int		keyval_index;

	keyval_index = -1;
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (src[j] == arr[i][j] && src[j] != '=' && arr[i][j] != '=')
			j++;
		if (src[j] == '=' && arr[i][j] == '=')
		{
			keyval_index = i;
			break;
		}
	}
	return (keyval_index) ;
}

int				key_in_env(char **arr, char *src, int size)
{
	int		i;
	int		j;
	int		keyval_index;

	keyval_index = -1;
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (src[j] == arr[i][j] && src[j] != '\0' && arr[i][j] != '=')
			j++;
		if (src[j] == '\0' && arr[i][j] == '=')
		{
			keyval_index = i;
			break;
		}
	}
	return (keyval_index) ;
}

int				change_env_val(char **arr, char *src, int index)
{
	char	*prev_string;

	prev_string = arr[index];
	arr[index] = ft_strdup(src);
	if (!arr[index])
		return (ERR);
	free(prev_string);
	return (SUCC);
}

int				add_env(t_darr *env, char *src)
{
	if (env->capacity <= env->size)
		resize_arr(env);
	env->arr[env->size++] = ft_strdup(src);
	return (SUCC);
}

int				resize_arr(t_darr *darr)
{
	int		i;
	char	**new_arr;

	new_arr = malloc(sizeof(char *) * (darr->capacity * 2));
	if (!new_arr)
		return (ERR);
	i = -1;
	while (++i < darr->size)
		new_arr[i] = darr->arr[i];
	free(darr->arr);
	darr->arr = new_arr;
	return (SUCC);
}

void			print_darr(t_darr *env)
{
	int		i;

	i = -1;
	while (++i < env->size)
		printf("%s\n", env->arr[i]);
}

void			delete_env(t_darr *env, char *key)
{
	int		keyptr;
	int		i;

	keyptr = key_in_env(env->arr, key, env->size);
	printf("keyptr : %d\n", keyptr);
	printf("-----------------------------------------\n");
	printf("-----------------------------------------\n");
	printf("-----------------------------------------\n");
	if (keyptr > 0)
	{
		printf("-------%s-----------\n", env->arr[keyptr]);
		free(env->arr[keyptr]);
		i = keyptr - 1;
		while (++i < env->size - 1)
			env->arr[i] = env->arr[i + 1];
		env->size--;
	}
	return ;
}
