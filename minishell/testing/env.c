/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 13:00:06 by mchun             #+#    #+#             */
/*   Updated: 2021/08/29 16:13:17 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./env.h"

int				init_env(t_env **env_struct, char **envp)
{
	int		i;
	t_env	*env ;

	env = *env_struct;
	i = 0;
	while (envp[i])
		i++;
	env->global_size = i;
	env->global_env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!env->global_env)
		return (ERR);
	while (*envp)
		*env->global_env++ = ft_strdup(*envp++);				//global_env 도 일일히 strdup해줘야함.
	*(env->global_env) = NULL;
	env->local_size = 0;
	env->local_env = (char **)malloc(sizeof(char *) * (0 + 1));
	if (!env->local_env)
		return (ERR);
	*(env->local_env) = NULL;
	return (SUCC);
}

int				env_add(t_env *env, char *env_toadd)
{
	int		keyptr;

	//이미 존재하는 환경변수/쉘 지역변수는 변수에 더하지 않는다.
	if (keyval_in_env(env->local_env, env_toadd, env->local_size) || keyval_in_env(env->global_env, env_toadd, env->global_size))
		return (SUCC);
	keyptr = key_in_env(env->global_env, env_toadd, env->local_size);
	if (keyptr > 0)
	{
		change_env_val(env->global_env, env_toadd, keyptr);
		return (SUCC);
	}
	keyptr = key_in_env(env->local_env, env_toadd, env->local_size);
	if (keyptr > 0)
	{
		change_env_val(env->local_env, env_toadd, keyptr);
		return (SUCC);
	}
	else
		add_env(env, env_toadd, env->local_size);
	return (SUCC);
}

int				keyval_in_env(char **arr , char *src, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (strcmp(arr[i], src) == 0)		//strcmp를 libft에 만들어야함.
			return (TRUE);
	}
	return (FALSE);
}

int				key_in_env(char **arr, char *src, int size)
{
	int		i;
	char	**arr_keyval;
	char	**src_keyval;
	int		keyval_index;

	keyval_index = -1;
	src_keyval = ft_split(src, '=');
	i = -1;
	while (++i < size)
	{
		arr_keyval = ft_split(arr[i], '=');
		if (strcmp(arr_keyval[0], src_keyval[0]) == 0)
			keyval_index = i;
		free(arr_keyval[0]);
		free(arr_keyval[1]);
		free(arr_keyval);
	}
	free(src_keyval[0]);
	free(src_keyval[1]);
	free(src_keyval);
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

int				add_env(t_env *env, char *src, int size)
{
	char	**new_local_env;
	int		i;

	new_local_env = (char **)malloc(sizeof(char *) * (env->local_size + 1 + 1));
	if (!new_local_env)
		return (ERR);
	i = 0;
	while (env->local_env[i] && ++i)
		new_local_env[i] = env->local_env[i];
	new_local_env[i] = ft_strdup(src);
	new_local_env[i + 1] = NULL;
	free(env->local_env);
	env->local_env = new_local_env;
	env->local_size++;
	return (SUCC);
}
