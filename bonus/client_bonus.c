/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:01:16 by maeskhai          #+#    #+#             */
/*   Updated: 2025/03/24 16:28:40 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_len(int n, int pid)
{
	int	i;

	i = 31;
	if (n < 0)
		exit(1);
	while (i >= 0)
	{
		if (n & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		i--;
	}
}

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
		usleep(300);
		i--;
	}
}

void	writing(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("message wsal\n");
}

int	main(int ac, char **av)
{
	int					i;
	int					pid;
	char				*s;
	static int			n;
	struct sigaction	action;

	action.sa_handler = writing;
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	if (ac != 3)
	{
		write(1, "Try next time : Typing ===>> <<pid>>  <<message>>\n", 50);
		return (EXIT_FAILURE);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	s = av[2];
	n = ft_strlen(s);
	send_len(n, pid);
	while (s[i])
	{
		send_bit(s[i], pid);
		i++;
	}
}
