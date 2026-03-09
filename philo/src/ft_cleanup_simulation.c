/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:24:49 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/09 13:38:24 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdlib.h>

void	ft_cleanup_forks(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->philo_count)
	{
		ft_destroy_mutex(sim, sim->forks + i, "ft_cleanup_forks()");
		i++;
	}
	free(sim->forks);
}

void	ft_cleanup_simulation(t_simulation *sim)
{
	ft_cleanup_forks(sim);
	ft_destroy_mutex(sim, &sim->running_lock, "ft_cleanup_simulation()");
	ft_destroy_mutex(sim, &sim->print_lock, "ft_cleanup_simulation()");
	free(sim->philos);
}
