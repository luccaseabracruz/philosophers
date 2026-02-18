/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:58:23 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/18 11:52:22 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

static t_result	ft_parse_rules(int argc, char **args, t_simulation *sim)
{
	if (argc < 5)
	{
		ft_put_error(ERR_MISS_ARGS);
		return (FAILURE);
	}
	sim->num_philosophers = ft_atol(args[0]);
	sim->time_to_die = ft_atol(args[1]);
	sim->time_to_eat = ft_atol(args[2]);
	sim->time_to_sleep = ft_atol(args[3]);
	if (args[4])
		sim->meals_counter_target = ft_atol(args[4]);
	else
		sim->meals_counter_target = -1;
	if (sim->time_to_die < 0 || sim->time_to_eat < 0
		|| sim->time_to_sleep < 0 || (args[4] && sim->meals_counter_target < 0))
	{
		ft_put_error("Error: negative numbers are not allowed.\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

static t_result	ft_init_forks(int num, pthread_mutex_t **forks)
{
	int	i;

	if (!forks)
		return (FAILURE);
	*forks = malloc(num * sizeof(pthread_mutex_t));
	if (!(*forks))
	{
		ft_put_error(ERR_MALLOC);
		return (FAILURE);
	}
	i = 0;
	while (i < num)
	{
		pthread_mutex_init((*forks) + i, NULL);
		i++;
	}
	return (SUCCESS);
}

static void	ft_assign_forks(t_philosopher *philosopher)
{
	pthread_mutex_t	*forks;
	int				num_philosophers;
	int				i;

	forks = philosopher->sim->forks;
	num_philosophers = philosopher->sim->num_philosophers;
	i = philosopher->id - 1;
	philosopher->left_fork = forks + i;
	philosopher->right_fork = forks + ((i + 1) % num_philosophers);
	if (philosopher->id % 2 != 0)
	{
		philosopher->first_fork = philosopher->left_fork;
		philosopher->second_fork = philosopher->right_fork;
	}
	else
	{
		philosopher->first_fork = philosopher->right_fork;
		philosopher->second_fork = philosopher->left_fork;
	}
}

static t_result	ft_init_philosophers(t_simulation *sim)
{
	t_philosopher	*philosophers;
	int				i;

	sim->philosophers = malloc(sim->num_philosophers * sizeof(t_philosopher));
	if (!sim->philosophers)
	{
		ft_put_error(ERR_MALLOC);
		return (FAILURE);
	}
	philosophers = sim->philosophers;
	memset(philosophers, 0, sim->num_philosophers * sizeof(t_philosopher));
	i = 0;
	while (i < sim->num_philosophers)
	{
		philosophers[i].id = i + 1;
		philosophers[i].sim = sim;
		philosophers[i].last_meal = ft_get_timestamp(MILISECONDS);
		ft_assign_forks(philosophers + i);
		i++;
	}
	return (SUCCESS);
}

t_result	ft_init_simulation(int argc, char **argv, t_simulation *sim)
{
	if (ft_parse_rules(argc, argv + 1, sim) != SUCCESS)
		return (FAILURE);
	if (ft_init_forks(sim->num_philosophers, &sim->forks) != SUCCESS)
		return (FAILURE);
	if (pthread_mutex_init(&sim->print_lock, NULL) != SUCCESS)
	{
		ft_cleanup_forks(sim->forks, sim->num_philosophers);
		return (FAILURE);
	}
	if (pthread_mutex_init(&sim->running_lock, NULL))
	{
		ft_cleanup_forks(sim->forks, sim->num_philosophers);
		pthread_mutex_destroy(&sim->print_lock);
		return (FAILURE);
	}
	if (ft_init_philosophers(sim) != SUCCESS)
	{
		ft_cleanup_forks(sim->forks, sim->num_philosophers);
		pthread_mutex_destroy(&sim->print_lock);
		pthread_mutex_destroy(&sim->running_lock);
		return (FAILURE);
	}
	return (SUCCESS);
}
