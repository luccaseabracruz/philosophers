/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring_routine.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:49:58 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/18 09:26:31 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
#include <pthread.h>

#include <stdio.h>

static t_bool	ft_is_satisfied(t_philosopher *philosopher)
{
	int	target;

	target = philosopher->sim->meals_counter_target;
	if (target >= 0 && philosopher->meals_counter >= target)
		return (TRUE);
	else
		return (FALSE);
}

static t_bool	ft_is_dead(t_philosopher *philosopher)
{
	long	current_time;
	long	diff;

	current_time = ft_get_timestamp(MILISECONDS);
	diff = current_time - philosopher->last_meal;
	if (diff >= philosopher->sim->time_to_die)
	{
		pthread_mutex_lock(&philosopher->sim->print_lock);
		printf("last: %ld\ncurrent: %ld\ndiff: %ld\n",
			philosopher->last_meal, current_time, diff);
		pthread_mutex_unlock(&philosopher->sim->print_lock);
		return(TRUE);
	}
	else
		return (FALSE);
}

static void	ft_check_all_philosophers(t_simulation *sim)
{
	int				i;
	int				satisfied_philosophers;
	t_philosopher	*cur_philosopher;

	i = 0;
	satisfied_philosophers = 0;
	while (i < sim->num_philosophers)
	{
		cur_philosopher = sim->philosophers + i;
		if (ft_is_dead(cur_philosopher) == TRUE)
		{
			ft_set_running(sim, FALSE);
			ft_put_msg(cur_philosopher, MSG_DIE, NULL);
			return ;
		}
		else if (ft_is_satisfied(cur_philosopher) == TRUE)
			satisfied_philosophers++;
		i++;
	}
	if (satisfied_philosophers == sim->num_philosophers)
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
