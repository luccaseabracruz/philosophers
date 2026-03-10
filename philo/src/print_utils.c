/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:24:10 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/10 20:53:29 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
#include <stdio.h>

static size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_put_str_fd(int fd, char *str)
{
	size_t	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	write(fd, str, len);
}

void	ft_put_error(t_simulation *sim, char *function, char *message)
{
	int	res;

	if (!sim)
		return ;
	res = pthread_mutex_lock(&sim->print_lock);
	if (res != SUCCESS)
	{
		ft_put_str_fd(STDERR_FILENO, ERR_PRINT_LOCK_LOCK);
		ft_set_running(sim, FALSE);
		return ;
	}
	ft_put_str_fd(STDERR_FILENO, ERR_PREFIX);
	if (function)
	{
		ft_put_str_fd(STDERR_FILENO, ": ");
		ft_put_str_fd(STDERR_FILENO, function);
	}
	if (message)
	{
		ft_put_str_fd(STDERR_FILENO, ": ");
		ft_put_str_fd(STDERR_FILENO, message);
	}
	ft_put_str_fd(STDERR_FILENO, "\n");
	if (pthread_mutex_unlock(&sim->print_lock) != SUCCESS)
		ft_put_str_fd(STDERR_FILENO, ERR_PRINT_LOCK_UNLOCK);
}
