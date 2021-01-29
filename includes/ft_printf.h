/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:47:46 by mchun             #+#    #+#             */
/*   Updated: 2021/01/29 15:57:26 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# define F_PRECISION	1
# define F_WIDTH 		2
# define F_LEFT_JUSTIFY	4
# define F_ZERO			8
# define F_ONLY_DOT		16

typedef struct	s_parse_info
{
	int		flag;
	int		width;
	int		prec;
	char	type;
}				t_parse_info;

int				ft_printf(const char *str, ...);
void			parse_info_renew(t_parse_info *p_info);
int				reach_delim(const char *str, int i);
int				handle_p_info(t_parse_info *p_info);
int				print_handler(t_parse_info *p_info, va_list *ap, int *num);

int				pf_parse(const char *s, t_parse_info *p_info, va_list *ap);
int				parse_type(const char *s, t_parse_info *p_info);
int				parse_precision(const char *s, t_parse_info *info, va_list *ap);
int				parse_width(const char *s, t_parse_info *info, va_list *ap);
int				parse_flag(const char *s, t_parse_info *p_info);

char			*printer_width_helper(t_parse_info *info, int len, char *sub);

int				printer_type_c(t_parse_info *p_info, va_list *ap, int *l);
int				printer_type_s(t_parse_info *p_info, va_list *ap, int *l);
int				printer_type_p(t_parse_info *p_info, va_list *ap, int *l);
int				printer_type_perc(t_parse_info *p_info, int *l);
int				printer_type_xud(t_parse_info *p_info, va_list *ap, int *l);

char			*make_subxud(t_parse_info *p, unsigned int num, int *digitlen);
char			*xud_substr_maker(t_parse_info *p, unsigned int num, int *dig);

void			free_all(void *a, void *b, void *c, void *d);



void	debug_p_info(t_parse_info *p);

#endif
