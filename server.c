/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:24:40 by abegou            #+#    #+#             */
/*   Updated: 2026/03/06 18:18:39 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minitalk.h"

static void	handler(int sig)
{
	unsigned char	c;
	unsigned int	oct;

	c = 0;
	oct = 0;
	if (sig == SIGUSR2)
		c |= (1 << (7 - oct));
//	else if (sig == SIGUSR2)
//		c |= (0 << (7 - oct));
	oct++;
	if (oct == 8)
	{
		ft_printf("%c", c);
		c = 0;
		oct = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sa.sa_flags = SA_SIGINFO;
	ft_printf("%d", getpid());
	while(1)
		pause();
}
