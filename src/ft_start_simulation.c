/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:33:54 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/19 15:21:18 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <unistd.h>

static t_result	ft_create_threads_step(t_simulation *sim, int start, int step)
{
	t_philosopher	*philo;
	int				i;

	i = start;
	while (i < sim->philo_count)
	{
		philo = sim->philos + i;
		if (pthread_create(&philo->thread, NULL,
				ft_routine, (void *)philo) != SUCCESS)
		{
			ft_put_error(&sim->print_lock, "ft_create_threads_step()",
				ERR_THREAD_CREATE);
			return (FAILURE);
		}
		i += step;
	}
	return (SUCCESS);
}

static t_result	ft_create_threads(t_simulation *sim)
{
	if (pthread_create(&sim->monitoring_thread,
			NULL, ft_monitoring_routine, sim) != SUCCESS)
	{
		ft_put_error(&sim->print_lock, "ft_create_threads()",
			ERR_THREAD_CREATE);
		return (FAILURE);
	}
	if (ft_create_threads_step(sim, 0, 2) != SUCCESS)
		return (FAILURE);
	usleep(1000);
	if (ft_create_threads_step(sim, 1, 2) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

static t_result	ft_join_threads(t_simulation *sim)
{
	t_philosopher	*philo;
	int				i;

	i = 0;
	while (i < sim->philo_count)
	{
		philo = sim->philos + i;
		if (pthread_join(philo->thread, NULL) != SUCCESS)
		{
			ft_put_error(&sim->print_lock, NULL, ERR_THREAD_JOIN);
			return (FAILURE);
		}
		i++;
	}
	if (pthread_join(sim->monitoring_thread, NULL))
	{
		ft_put_error(&sim->print_lock, NULL, ERR_THREAD_JOIN);
		return (FAILURE);
	}
	return (SUCCESS);
}

t_result	ft_start_simulation(t_simulation *sim)
{
	ft_set_running(sim, TRUE);
	sim->start_timestamp = ft_get_timestamp(MILISECONDS);
	if (ft_create_threads(sim) != SUCCESS || ft_join_threads(sim) != SUCCESS)
	{
		ft_set_running(sim, FALSE);
		return (FAILURE);
	}
	return (SUCCESS);
}
