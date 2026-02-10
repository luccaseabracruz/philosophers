/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:33:54 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/10 16:51:55 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_start_simulation(t_simulation *sim)
{
	int				i;
	t_philosopher	*philo;

	i = -1;
	while (++i < sim->num_philosophers)
	{
		philo = sim->philosophers + i;
		if (pthread_create(&philo->thread, NULL, ft_routine, (void *)philo)
			!= SUCCESS)
		{
			ft_puterror(ERR_THREAD_CREATE);
			return (FAILURE);
		}
	}
	i = -1;
	while (++i < sim->num_philosophers)
	{
		philo = sim->philosophers + i;
		if (pthread_join(philo->thread, NULL) != SUCCESS)
		{
			ft_puterror(ERR_THREAD_JOIN);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
