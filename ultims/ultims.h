/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultims.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:14:00 by maeskhai          #+#    #+#             */
/*   Updated: 2025/03/24 15:47:21 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ULTIMS_H
# define ULTIMS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_putstr(char *s);
int		ft_putadd(void *p);
int		ft_puthexa(unsigned int n, char format);
void	ft_free(char *s);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
#endif
