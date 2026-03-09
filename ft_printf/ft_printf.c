/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:25:00 by abegou            #+#    #+#             */
/*   Updated: 2025/11/18 16:01:11 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_try(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_putstr(str);
	free(str);
	return (len);
}

static int	format_check(const char format, va_list(args))
{
	int	len;

	len = 0;
	if (!format)
		return (-1);
	else if (format == '%')
		len += ft_putchar(format);
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		len += ft_try(va_arg(args, int));
	else if (format == 'u')
		len += ft_putnbr(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_puthexl(va_arg(args, unsigned int));
	else if (format == 'X')
		len += ft_puthexh(va_arg(args, unsigned int));
	else if (format == 'p')
		len += ft_putptr(va_arg(args, void *));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, format);
	len = 0;
	i = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += format_check(format[i + 1], args);
			i += 2;
		}
		else
		{
			len += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}
