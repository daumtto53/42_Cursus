/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:47:46 by mchun             #+#    #+#             */
/*   Updated: 2021/01/26 17:55:00 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include "libft/libft.h"

# define F_PRECISION	1
# define F_WIDTH 		2
# define F_LEFT_JUSTIFY	4
# define F_ZERO			8

typedef struct		s_parse_info
{
	int		flag;
	char	type;
	int		width;
	int		prec;
}					t_parse_info;

int		ft_printf(const char *str, ...);
#endif
