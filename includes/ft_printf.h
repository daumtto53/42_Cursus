/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:47:46 by mchun             #+#    #+#             */
/*   Updated: 2021/02/09 20:37:13 by mchun            ###   ########.fr       */
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
# define F_POUND		16
# define F_SPACE		32
# define F_PLUS			64

# define FT_PF_LL		2
# define FT_PF_L		1
# define FT_PF_I		0
# define FT_PF_H		-1
# define FT_PF_HH		-2

typedef struct	s_info
{
	int		flag;
	int		width;
	int		prec;
	int		len;
	char	type;
}				t_info;

int				ft_printf(const char *str, ...);

int				pf_parse(const char *s, t_info *info, va_list *ap);

void			printer_type_c(t_info *info, va_list *ap, long long *l);
void			printer_type_s(t_info *info, va_list *ap, long long *l);
void			printer_type_p(t_info *info, va_list *ap, long long *l);
void			printer_type_perc(t_info *info, long long *l);

void			printer_type_hex(t_info *info, va_list *ap, long long *len);
void			printer_type_oct(t_info *info, va_list *ap, long long *len);
void			printer_type_int(t_info *info, va_list *ap, long long *len);
int				pf_is_sign(long long num, t_info *info);
void			printer_type_uint(t_info *info, va_list *ap, long long *len);
void			printer_type_n(t_info *info, va_list *ap, long long *len);
void			printer_type_nhh(va_list *ap, long long *len);
void			printer_type_nh(va_list *ap, long long *len);
void			printer_type_ni(va_list *ap, long long *len);
void			printer_type_nl(va_list *ap, long long *len);
void			printer_type_nll(va_list *ap, long long *len);

#endif
