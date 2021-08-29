/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 12:36:22 by mchun             #+#    #+#             */
/*   Updated: 2021/08/29 15:19:05 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../42_Cursus/libft/libft.h"
#define ERR		0
#define SUCC	1

#define TRUE	1
#define	FALSE	0

typedef struct	s_env
{
	char		**global_env;
	char		**local_env;;
	int			global_size;
	int			local_size;
}				t_env;




