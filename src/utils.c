/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:24:10 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/16 18:07:51 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
#include <stdio.h>

static int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int	i;

// 	if (!s1 || !s2)
// 	return (0);
// 	i = 0;
// 	while (s1[i] && s2[i])
// 	i++;
// 	return (s1[i] - s2[i]);
// }

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
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_put_error(char *msg)
{
	int	len;

	if (msg)
	{
		len = ft_strlen(msg);
		write(STDERR_FILENO, msg, len);
	}
}

void	ft_put_message(t_philosopher *philosopher, char *msg, long *timestamp)
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
