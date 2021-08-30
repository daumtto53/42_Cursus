/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:20:38 by mchun             #+#    #+#             */
/*   Updated: 2021/08/30 01:04:05 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
FOR TESTING ENV
*/
#include "env.h"

int		main(int argc, char **argv, char **envp)
{

	char	**str;

	t_darr	*env;
	int		i;

	env = init_darr(envp);

	i = -1;
	print_darr(env);
	scanf("%d", &i);

	/*export*/
	/* 동적할당한 env 확인 */
	{
		{
			env_add(env, "mchun=1");
			print_darr(env);
			scanf("%d", &i);
			env_add(env, "mchun=3");
			print_darr(env);
			scanf("%d", &i);
		}
	}


		// adding이 제대로 되는가?
		{
			env_add(env, "testing_0=0");
			print_darr(env);
			scanf("%d", &i);
			env_add(env, "testing_1=1");
			print_darr(env);
			scanf("%d", &i);
			env_add(env, "testing_2=2");
			print_darr(env);
			scanf("%d", &i);
			env_add(env, "testing_3=3");
			print_darr(env);
			scanf("%d", &i);
		}

		// 이전에 만들어놓은 변수를 바꿀 수 있는가?
		{
			env_add(env, "testing_1=4");
			print_darr(env);
			scanf("%d", &i);
			env_add(env, "mchun=1001");
			print_darr(env);
			scanf("%d", &i);
			env_add(env, "mchun=123");
			print_darr(env);
			scanf("%d", &i);
		}

		//	"KEY=" 도 환경변수에 저장이 되는가?
		{
			env_add(env, "NULL_TEST=");
			print_darr(env);
			scanf("%d", &i);
		}

	//deleting = UNSET
	{
		delete_env(env, "mchun");
		print_darr(env);
		scanf("%d", &i);
		delete_env(env, "NULL_TEST");
		print_darr(env);
		scanf("%d", &i);
		delete_env(env, "testing_1");
		print_darr(env);
		scanf("%d", &i);
		delete_env(env, "testing_2");
		print_darr(env);
		scanf("%d", &i);
	}

	i = -1;
	while (env->size > ++i)
		free(env->arr[i]);
	free(env->arr);
	free(env);
	return (0);
}
