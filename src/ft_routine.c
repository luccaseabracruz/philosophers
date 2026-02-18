/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:46:41 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/18 16:26:18 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>

void	*ft_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (ft_is_running(philo->sim))
	{
		ft_take_fork(philo, RIGHT);
		ft_take_fork(philo, LEFT);
		ft_eat(philo);
		ft_release_forks(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (arg);
}
