/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:33:54 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/16 18:34:58 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_result	ft_create_threads(t_simulation *sim)
{
	t_philosopher	*philo;
	int				i;

	if (pthread_create(&sim->monitoring_thread,
			NULL, ft_monitoring_routine, sim) != SUCCESS)
	{
		ft_put_error(ERR_THREAD_CREATE);
		return (FAILURE);
	}
	i = 0;
	while (i < sim->num_philosophers)
	{
		philo = sim->philosophers + i;
		if (pthread_create(&philo->thread, NULL, ft_routine, (void *)philo)
			!= SUCCESS)
		{
			ft_put_error(ERR_THREAD_CREATE);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

static t_result	ft_join_threads(t_simulation *sim)
{
	t_philosopher	*philo;
	int				i;

	if (pthread_join(sim->monitoring_thread, NULL))
	{
		ft_put_error(ERR_THREAD_JOIN);
		return (FAILURE);
	}
	i = 0;
	while (i < sim->num_philosophers)
	{
		philo = sim->philosophers + i;
		if (pthread_join(philo->thread, NULL) != SUCCESS)
		{
			ft_put_error(ERR_THREAD_JOIN);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

t_result	ft_start_simulation(t_simulation *sim)
{
	ft_set_running(sim, TRUE);
	if (ft_create_threads(sim) != SUCCESS || ft_join_threads(sim) != SUCCESS)
	{
		ft_set_running(sim, FALSE);
		return (FAILURE);
	}
	return (SUCCESS);
}
