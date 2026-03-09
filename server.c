/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:24:40 by abegou            #+#    #+#             */
/*   Updated: 2026/03/07 18:36:00 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig)
{
	static unsigned char	c = 0;
	static unsigned int		oct = 0;
	static char				*str = NULL;
	char					buffer[2];
	char					*join;

	if (sig == SIGUSR2)
		c |= (1 << (7 - oct));
	oct++;
	if (oct == 8)
	{
		if (c == '\0')
		{
			ft_printf("%s", str);
			free(str);
			str = NULL;
		}
		else
		{
			if (str == NULL)
				str = ft_strdup("");
			buffer[0] = c;
			buffer[1] = '\0';
			join = ft_strjoin(str, buffer);
			free(str);
			str = join;
		}
	}
	oct = 0;
	c = 0;
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
	ft_printf("%d\n", getpid());
	while (1)
		pause();
}
