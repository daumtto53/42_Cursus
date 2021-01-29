/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:47:46 by mchun             #+#    #+#             */
/*   Updated: 2021/01/29 22:34:28 by mchun            ###   ########.fr       */
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

char			*printer_width_helper(t_info *info, int len, char *sub);

int				printer_type_c(t_info *info, va_list *ap, int *l);
int				printer_type_s(t_info *info, va_list *ap, int *l);
int				printer_type_p(t_info *info, va_list *ap, int *l);
int				printer_type_perc(t_info *info, int *l);
int				printer_type_xud(t_info *info, va_list *ap, int *l);

char			*make_subxud(t_info *info, unsigned int num, int *digitlen);
char			*xud_substr_maker(t_info *info, unsigned int num, int *dig);

void			free_all(void *a, void *b, void *c, void *d);
int				is_valid_type(char c);



void	debug_p_info(t_info *p);

#endif
