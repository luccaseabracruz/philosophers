/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring_routine.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:49:58 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/10 21:31:24 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
#include <pthread.h>

#include <stdio.h>

static t_bool	ft_is_satisfied(t_philosopher *philo)
{
	int	target;

	target = philo->sim->meals_counter_target;
	if (target >= 0 && philo->meals_counter >= target)
		return (TRUE);
	else
		return (FALSE);
}

static t_bool	ft_is_dead(t_philosopher *philo)
{
	long	current_time;
	long	diff;

	current_time = ft_get_timestamp(MILISECONDS);
	diff = current_time - philo->last_meal;
	if (diff >= philo->sim->time_to_die)
		return (TRUE);
	else
		return (FALSE);
}

static void	ft_check_all_philosophers(t_simulation *sim)
{
	int				i;
	int				satisfied_philos;
	t_philosopher	*cur_philo;

	i = 0;
	satisfied_philos = 0;
	while (i < sim->philo_count)
	{
		cur_philo = sim->philos + i;
		if (ft_is_dead(cur_philo) == TRUE)
		{
			ft_print_action(cur_philo, DIE, NULL);
			ft_set_running(sim, FALSE);
			return ;
		}
		else if (ft_is_satisfied(cur_philo) == TRUE)
			satisfied_philos++;
		i++;
	}
	if (satisfied_philos == sim->philo_count)
		ft_set_running(sim, FALSE);
}

void	*ft_monitoring_routine(void *arg)
{
	t_simulation	*sim;

	sim = (t_simulation *)arg;
	while (ft_is_running(sim) == TRUE)
	{
		usleep(MONITORING_INTERVAL_MS * 1000);
		ft_check_all_philosophers(sim);
	}
	return (arg);
}
