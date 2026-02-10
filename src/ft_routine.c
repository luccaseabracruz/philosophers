/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:46:41 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/10 16:55:49 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>

static void	ft_eat(t_philosopher *philosopher)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philosopher->id % 2 != 0)
	{
		first_fork = philosopher->left_fork;
		second_fork = philosopher->right_fork;
	}
	else
	{
		first_fork = philosopher->right_fork;
		second_fork = philosopher->left_fork;
	}
	pthread_mutex_lock(first_fork);
	printf("%d %s\n", philosopher->id, MSG_FORK);
	pthread_mutex_lock(second_fork);
	printf("%d %s\n", philosopher->id, MSG_FORK);
	philosopher->meals_counter++;
	//TODO(): Register timestamp
	printf("%d %s\n", philosopher->id, MSG_EAT);
	//TODO(): Wait TIME_TO_EAT ms
	pthread_mutex_unlock(first_fork);
	pthread_mutex_unlock(second_fork);
}

static void	ft_sleep(t_philosopher *philosopher)
{
	printf("%d %s\n", philosopher->id, MSG_SLEEP);
	//TODO(): Wait TIME_TO_SLEEP ms
}

static void	ft_think(t_philosopher *philosopher)
{
	printf("%d %s\n", philosopher->id, MSG_THINK);
}

void	*ft_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	while (philosopher->meals_counter < philosopher->sim->meals_counter_target)
	{
		ft_eat(philosopher);
		ft_sleep(philosopher);
		ft_think(philosopher);
	}
	return (arg);
}
