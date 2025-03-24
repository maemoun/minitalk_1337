/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:07:09 by maeskhai          #+#    #+#             */
/*   Updated: 2025/03/24 16:29:21 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(300);
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	char	*s;

	if (ac != 3)
	{
		write(1, "Try next time : Typing ===>> ", 29);
		write(1, " <<pid>>  <<message>>\n", 22);
		return (EXIT_FAILURE);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	s = av[2];
	while (s[i])
	{
		send_bit(s[i], pid);
		i++;
	}
	return (EXIT_SUCCESS);
}
