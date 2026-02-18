/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:24:49 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/18 16:22:21 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdlib.h>

void	ft_cleanup_forks(pthread_mutex_t *forks, int philo_count)
{
	int	i;

	i = 0;
	while (i < philo_count)
	{
		pthread_mutex_destroy(forks + i);
		i++;
	}
	free(forks);
}

void	ft_cleanup_simulation(t_simulation *sim)
{
	ft_cleanup_forks(sim->forks, sim->philo_count);
	pthread_mutex_destroy(&sim->print_lock);
	pthread_mutex_destroy(&sim->running_lock);
	free(sim->philosophers);
}
