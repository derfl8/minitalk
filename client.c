/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:24:32 by abegou            #+#    #+#             */
/*   Updated: 2026/03/06 18:27:08 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send(unsigned int pid, char c)
{
	unsigned int	oct;
	
	oct = 7;
	while (oct >= 0)
	{
		if ((c >> oct) & 1)
			kill(pid, SIGUSR1);
		else //if ((c >> oct) & 0)
			kill(pid, SIGUSR2);
		usleep(100);
		oct--;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	else if (ft_atoi(av[1]) < 1)
		ft_printf("%s", "Wrong PID dumbass");
	send(ft_atoi(av[1]), 'a');
	return (0);
}
