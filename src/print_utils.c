/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:24:10 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/23 12:10:26 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
#include <stdio.h>

void	ft_put_error(pthread_mutex_t *lock, char *message, char *function)
{
	if (!lock && !message && !function)
		return ;
	pthread_mutex_lock(lock);
	if (message && function)
		printf("%s: %s: %s\n", ERR_PREFIX, function, message);
	else if (message)
		printf("%s: %s\n", ERR_PREFIX, message);
	else if (function)
		printf("%s: %s\n", ERR_PREFIX, function);
	pthread_mutex_unlock(lock);
}

void	ft_print_action(t_philosopher *philo, char *msg, long *timestamp)
{
	long	temp;
	long	start;
	long	last_numbers;

	start = philo->sim->start_timestamp;
	if (!timestamp)
	{
		temp = ft_get_timestamp(MILISECONDS);
		timestamp = &temp;
	}
	last_numbers = (*timestamp - start) % 1000;
	if (msg)
	{
		pthread_mutex_lock(&philo->sim->print_lock);
		if (ft_is_running(philo->sim))
			printf("%03ld %d %s\n", last_numbers, philo->id, msg);
		pthread_mutex_unlock(&philo->sim->print_lock);
	}
}
