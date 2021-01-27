/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:47:46 by mchun             #+#    #+#             */
/*   Updated: 2021/01/27 17:53:58 by mchun            ###   ########.fr       */
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
# define F_ONLY_DOT		16

typedef struct		s_parse_info
{
	int		flag;
	int		width;
	int		prec;
	char	type;
}					t_parse_info;

int		ft_printf(const char *str, ...);
void	parse_info_renew(t_parse_info *p_info);
int		reach_delim(const char *str, int i);
int		handle_parse_info(t_parse_info *p_info);

int		pf_parse(const char *s, t_parse_info *p_info, va_list *ap);
int		parse_type(const char *s, t_parse_info *p_info);
int		parse_precision(const char *s, t_parse_info *p_info, va_list *ap);
int		parse_width(const char *s, t_parse_info *p_info, va_list *ap);
int		parse_flag(const char *s, t_parse_info *p_info);

int		printer_type_c(t_parse_info *p_info, va_list *ap);
int		printer_type_s(t_parse_info *p_info, va_list *ap);
int		printer_type_s_helper(t_parse_info *p, va_list *ap, char **f, int *l);
int		printer_type_p(t_parse_info *p_info, va_list *ap);
int		printer_type_p_helper(t_parse_info *p, va_list *a, char **f, char **b);
int		printer_type_perc(t_parse_info *p_info, va_list *ap);
int		printer_type_x(t_parse_info *p_info, va_list *ap);
int		printer_type_d(t_parse_info *p_info, va_list *ap);
int		printer_type_u(t_parse_info *p_info, va_list *ap);

void	free_all(void *a, void *b, void *c, void *d);


#endif
