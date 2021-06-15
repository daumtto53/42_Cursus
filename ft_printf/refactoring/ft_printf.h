/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:47:46 by mchun             #+#    #+#             */
/*   Updated: 2021/01/30 15:48:40 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# define F_PREC			1
# define F_WIDTH 		2
# define F_LJUST		4
# define F_ZERO			8
# define F_ONLY_DOT		16

typedef struct	s_info
{
	int		flag;
	int		width;
	int		prec;
	char	type;
}				t_info;

int				ft_printf(const char *str, ...);
void			parse_info_renew(t_info *info);
int				print_until_delim(const char *str, int i, int *len);
int				handle_p_info(t_info *info);
int				print_handler(t_info *p_info, va_list *ap, int *num);

int				pf_parse(const char *s, t_info *info, va_list *ap);
int				parse_type(const char *s, t_info *info);
int				parse_precision(const char *s, t_info *info, va_list *ap);
int				parse_width(const char *s, t_info *info, va_list *ap);
int				parse_flag(const char *s, t_info *info);

int				printer_type_c(t_info *info, va_list *ap, int *l);
int				printer_type_s(t_info *info, va_list *ap, int *l);
int				printer_type_p(t_info *info, va_list *ap, int *l);
int				printer_type_perc(t_info *info, int *l);

char			*xud_substr_maker(t_info *info, int num);
int				printer_type_xud(t_info *info, va_list *ap, int *l);
void			printer_type_xud2(t_info *info, char *str, int sign, int b_num);

void			debug_p_info(t_info *p);

#endif
