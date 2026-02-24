/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:46:41 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/19 12:48:39 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <unistd.h>

void	*ft_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (ft_is_running(philo->sim))
	{
		ft_take_fork(philo, RIGHT);
		if (philo->sim->philo_count == 1)
		{
			pthread_mutex_unlock(philo->right_fork);
			usleep(philo->sim->time_to_die * 1000);
			break ;
		}
		ft_take_fork(philo, LEFT);
		ft_eat(philo);
		ft_release_forks(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (arg);
}
