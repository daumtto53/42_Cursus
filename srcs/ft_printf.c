/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:50:01 by mchun             #+#    #+#             */
/*   Updated: 2021/02/05 21:16:14 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parse_info_renew(t_info *info)
{
	info->flag = 0;
	info->prec = 0;
	info->type = 0;
	info->width = 0;
}

int		print_controller(t_info *info, va_list *ap, int *ft_errno)
{
	char	t;
	int		len;

	t = info->type;
	if (t == 'c')
		len = printer_type_c(va_arg(*ap, int), info);
	else if (t == 's')
		len = printer_type_s(va_arg(*ap, char *));
	else if (t == 'p')
		len = printer_type_p(va_arg(*ap, void *), info, ft_errno);
	else if (t == 'x' || t == 'X')
		len = printer_type_hex(va_arg(*ap, int), info, ft_errno);
	else if (t == 'd' || t == 'i')
		len = printer_type_int(va_arg(*ap, int), info, ft_errno);
	else if (t == 'u')
		len = printer_type_uint(va_arg(*ap, int), info, ft_errno);
	else if (t == '%')
		len = printer_type_c('%', info);
	else
		*ft_errno = FT_ERR;
	return (len);
}

int		verify_p_info(t_info *info, int *ft_errno)
{
	if (!ft_strchr("cspudxXi", info->type))
		*ft_errno = FT_ERR;
	if (info->width >= 2147483646 || info->prec >= 2147483646)
		*ft_errno = FT_ERR;
	if (!ft_strchr("diuxX", info->type) && \
			(info->flag & F_ZERO & info->flag & F_PREC))
		info->flag &= (~F_ZERO);
	if (info->prec < 0)
	{
		info->prec = 0;
		info->flag &= (~F_PREC);
	}
	if (info->width < 0)
	{
		info->width *= -1;
		info->flag |= (F_LJUST);
	}
	return (FT_NORMAL);
}

int		print_until_delim(char **str, int *ft_errno)
{
	const char	*str_unchanged;
	const char	*str_changed;
	int		len;

	str_changed = *str;
	str_unchanged = *str;
	while (*str_changed != '%' && *str_changed != '\0')
		str_changed++;
	if (write(1, str_unchanged, str_changed- str_unchanged) < 0)
		*ft_errno = FT_ERR;
	len = str_changed - str_unchanged;
	*str = (char *)str_changed;
	return (len);
}

int		ft_printf(const char *str, ...)
{
	va_list			ap;
	t_info			info;
	int				len;
	int				ft_errno;

	ft_errno = FT_NORMAL;
	va_start(ap, str);
	len = 0;
	while (*str != '\0')
	{
		parse_info_renew(&info);
		len += print_until_delim((char **)&str, &ft_errno);		//str : %에 위치함.
		if (*str == '\0')
			return (len);
		pf_parse((char **)&str, &info, &ap);
		verify_p_info(&info, &ft_errno);
		if (ft_errno == FT_ERR)
			return (-1);
		len += print_controller(&info, &ap, &ft_errno);
		if (ft_errno == FT_ERR)
			return (-1);
	}
	va_end(ap);
	return (len);
}
