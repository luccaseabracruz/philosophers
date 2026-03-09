/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:24:10 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/09 20:56:37 by lseabra-         ###   ########.fr       */
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
	if (message && function)
		printf("%s: %s: %s\n", ERR_PREFIX, function, message);
	else if (message)
		printf("%s: %s\n", ERR_PREFIX, message);
	else if (function)
		printf("%s: %s\n", ERR_PREFIX, function);
	if (pthread_mutex_unlock(&sim->print_lock) != SUCCESS)
		ft_put_str_fd(STDERR_FILENO, ERR_PRINT_LOCK_UNLOCK);
}

void	ft_print_action(t_philosopher *philo, char *msg, long *timestamp)
{
	long			temp;
	long			start;
	long			last_numbers;
	int				res;
	t_simulation	*sim;

	if (!philo || !msg)
		return ;
	sim = philo->sim;
	start = sim->start_timestamp;
	if (!timestamp)
	{
		temp = ft_get_timestamp(MILISECONDS);
		timestamp = &temp;
	}
	last_numbers = (*timestamp - start) % 1000;
	res = ft_lock_mutex(sim, &sim->print_lock, "ft_print_action()");
	if (res != SUCCESS)
		return ;
	if (ft_is_running(sim))
	{
		printf(ORANGE"%03ld "BLUE"%d "TEAL"%s\n"RESET,
			last_numbers, philo->id, msg);
	}
	ft_unlock_mutex(sim, &sim->print_lock, "ft_print_action()");
}
