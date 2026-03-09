/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:24:32 by abegou            #+#    #+#             */
/*   Updated: 2026/03/09 11:20:26 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send(unsigned int pid, char c)
{
	int	oct;

	oct = 7;
	while (oct >= 0)
	{
		if ((c >> oct) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		oct--;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_printf("./client <PID> <message>\n");
		return (0);
	}
	else if (ft_atoi(av[1]) < 999999)
	{
		ft_printf("Wrong PID\n");
		return (1);
	}
	while (av[2][i])
		send(ft_atoi(av[1]), av[2][i++]);
	send(ft_atoi(av[1]), '\0');
	ft_printf("Message received by server");
	return (0);
}
