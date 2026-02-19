/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:24:10 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/19 10:08:52 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
#include <stdio.h>

static int	ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (1);
}

long	ft_atol(char *str)
{
	long	res;
	long	sign;
	int		i;

	if (!str)
		return (0);
	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}

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

void	ft_put_msg(t_philosopher *philo, char *msg, long *timestamp)
{
	long	temp;

	if (!timestamp)
	{
		temp = ft_get_timestamp(MILISECONDS);
		timestamp = &temp;
	}
	if (msg)
	{
		pthread_mutex_lock(&philosopher->sim->print_lock);
		printf("%ld %d %s\n", *timestamp, philosopher->id, msg);
		pthread_mutex_unlock(&philosopher->sim->print_lock);
	}
}
