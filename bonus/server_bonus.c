/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:01:08 by maeskhai          #+#    #+#             */
/*   Updated: 2025/03/24 15:44:23 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_list	g_s = {0, 31, 0, NULL, 0, 0, 0};

void	ft_variables(void)
{
	g_s.c = 0;
	g_s.j = 31;
	g_s.i = 0;
	g_s.len = 0;
	g_s.index = 0;
	g_s.c = 0;
	ft_free(g_s.str);
	g_s.str = NULL;
}

void	ft_check(int signum, int pid)
{
	g_s.c = g_s.c << 1;
	if (signum == SIGUSR1)
		g_s.c = g_s.c | 1;
	g_s.i++;
	if (g_s.i == 8)
	{
		g_s.str[g_s.index++] = g_s.c;
		g_s.c = 0;
		g_s.i = 0;
		if (g_s.index == g_s.len)
		{
			ft_printf("%s\n", g_s.str);
			g_s.len = 0;
			g_s.j = 31;
			g_s.index = 0;
			kill(pid, SIGUSR1);
		}
	}
}

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (info->si_pid != g_s.last_pid)
	{
		ft_variables();
		g_s.last_pid = info->si_pid;
	}
	if (g_s.j >= 0)
	{
		g_s.len = g_s.len << 1;
		if (signum == SIGUSR1)
			g_s.len = g_s.len | 1;
		g_s.j--;
		if (g_s.j == -1 && g_s.len > 0)
		{
			g_s.str = ft_calloc(g_s.len + 1, 1);
			if (!g_s.str)
				exit(1);
		}
	}
	else
		ft_check(signum, info->si_pid);
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("SERVER PID = %d\n", getpid());
	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
