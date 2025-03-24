/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:45:57 by maeskhai          #+#    #+#             */
/*   Updated: 2025/03/24 15:46:53 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultims.h"

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	tot;
	long long	check;

	sign = 1;
	tot = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		check = tot;
		tot = (tot * 10) + (*nptr - 48);
		if (tot / 10 != check && sign == 1)
			return (-1);
		else if (tot / 10 != check && sign == -1)
			return (0);
		nptr++;
	}
	return (tot * sign);
}
