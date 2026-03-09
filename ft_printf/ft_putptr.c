/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:34:42 by abegou            #+#    #+#             */
/*   Updated: 2025/11/18 15:44:14 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ptr(unsigned long long n)
{
	unsigned int	i;

	i = 0;
	if (n / 16)
		i += ft_puthex_ptr(n / 16);
	if (n % 16 < 10)
		i += ft_putchar((n % 16) + '0');
	else
		i += ft_putchar((n % 16) + 'W');
	return (i);
}

int	ft_putptr(void *ptr)
{
	int	len;

	len = 2;
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	len += ft_puthex_ptr((unsigned long long)ptr);
	return (len);
}
