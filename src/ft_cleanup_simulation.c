/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:24:49 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/16 08:29:56 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdlib.h>

void	ft_cleanup_forks(pthread_mutex_t *forks, int num_philosophers)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		pthread_mutex_destroy(forks + i);
		i++;
	}
	free(forks);
}

void	ft_cleanup_simulation(t_simulation *sim)
{
	ft_cleanup_forks(sim->forks, sim->num_philosophers);
	pthread_mutex_destroy(&sim->print_lock);
	free(sim->philosophers);
}
