/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 11:15:26 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/16 14:52:08 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <unistd.h>

void	ft_take_forks(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->first_fork);
	ft_put_message(philosopher, MSG_FORK, NULL);
	pthread_mutex_lock(philosopher->second_fork);
	ft_put_message(philosopher, MSG_FORK, NULL);
}

void	ft_release_forks(t_philosopher *philosopher)
{
	pthread_mutex_unlock(philosopher->first_fork);
	pthread_mutex_unlock(philosopher->second_fork);
}

void	ft_eat(t_philosopher *philosopher)
{
	philosopher->last_meal = ft_get_timestamp(MILISECONDS);
	ft_put_message(philosopher, MSG_EAT, &philosopher->last_meal);
	philosopher->meals_counter++;
	usleep(philosopher->sim->time_to_eat * 1000);
}

void	ft_sleep(t_philosopher *philosopher)
{
	ft_put_message(philosopher, MSG_SLEEP, NULL);
	usleep(philosopher->sim->time_to_sleep * 1000);
}

void	ft_think(t_philosopher *philosopher)
{
	ft_put_message(philosopher, MSG_THINK, NULL);
}
