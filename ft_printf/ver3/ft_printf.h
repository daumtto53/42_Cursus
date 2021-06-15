/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:47:46 by mchun             #+#    #+#             */
/*   Updated: 2021/02/05 21:25:48 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
#include <stdio.h>
# define FT_NORMAL		1
# define FT_ERR			0

# define F_PREC			1
# define F_WIDTH 		2
# define F_LJUST		4
# define F_ZERO			8
# define F_ONLY_DOT		16
# define SIGN			32

typedef struct	s_info
{
	int		flag;
	int		width;
	int		prec;
	char	type;
}				t_info;

int				ft_printf(const char *str, ...);
void			parse_info_renew(t_info *info);
int				print_until_delim(char **str, int *ft_errno);
int				verify_p_info(t_info *info, int *ft_errno);
int				print_controller(t_info *info, va_list *ap, int *ft_errno);

int		is_valid_type(char c);
int		is_valid_flag(char c);
int				ft_abstract_atoi(char **s, va_list *ap);
int		pf_parse(char **s, t_info *info, va_list *ap);

int				printer_type_c(unsigned int k, t_info *info);
int				printer_type_s(char *str, t_info *info);
int				printer_type_p(void *ptr, t_info *info, int *ft_errno);
 char		*printer_type_p_hexmaker(t_info *i, char *p);

char		*hex_interface(unsigned int num, t_info *info);
int				printer_type_hex(unsigned int num, t_info *info, int *ft_err);
int		hex_zero(unsigned int num, t_info *i);
int		hex_normal(unsigned int num, t_info *i);
int		hex_preczero(t_info *i);

int				printer_type_int(int num, t_info *info, int *ft_errno);
int		int_zero(long num, t_info *i);
int		int_normal(long num, t_info *i);
int		int_preczero(t_info *i);

int				printer_type_uint(unsigned int num, t_info *info, int *ft_errno);
int		uint_zero(unsigned int num, t_info *i);
int		uint_normal(unsigned int num, t_info *i);
int		uint_preczero(t_info *i);

#endif
