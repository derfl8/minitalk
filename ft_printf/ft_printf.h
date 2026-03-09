/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:08:44 by abegou            #+#    #+#             */
/*   Updated: 2025/11/17 18:39:37 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// libs
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// custom functions
int		ft_printf(const char *conv, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(unsigned int n);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
int		ft_puthexl(unsigned int n);
int		ft_puthexh(unsigned int n);
int		ft_putptr(void *ptr);

#endif
