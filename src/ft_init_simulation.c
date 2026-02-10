/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:58:23 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/10 16:53:41 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

static void	ft_parse_rules(char **args, t_simulation *sim)
{
	sim->num_philosophers = ft_atoi(args[0]);
	sim->time_to_die = ft_atoi(args[1]);
	sim->time_to_eat = ft_atoi(args[2]);
	sim->time_to_sleep = ft_atoi(args[3]);
	if (args[4])
		sim->meals_counter_target = ft_atoi(args[4]);
	else
		sim->meals_counter_target = -1;
}

static int	ft_init_forks(int num, pthread_mutex_t **forks)
{
	int	i;

	if (!forks)
		return (FAILURE);
	*forks = malloc(num * sizeof(pthread_mutex_t));
	if (!(*forks))
	{
		ft_puterror(ERR_MALLOC);
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

static int	ft_init_philosophers(t_simulation *sim)
{
	t_philosopher	*philosophers;
	int				i;

	sim->philosophers = malloc(sim->num_philosophers * sizeof(t_philosopher));
	if (!sim->philosophers)
	{
		ft_puterror(ERR_MALLOC);
		return (FAILURE);
	}
	philosophers = sim->philosophers;
	memset(philosophers, 0, sim->num_philosophers * sizeof(t_philosopher));
	i = 0;
	while (i < sim->num_philosophers)
	{
		philosophers[i].id = i + 1;
		philosophers[i].left_fork = sim->forks + i;
		philosophers[i].right_fork = sim->forks;
		philosophers[i].right_fork += (i + 1) % sim->num_philosophers;
		philosophers[i].sim = sim;
		i++;
	}
	return (SUCCESS);
}

int	ft_init_simulation(int argc, char **argv, t_simulation *sim)
{
	if (argc < 5)
	{
		ft_puterror(ERR_MISS_ARGS);
		return (FAILURE);
	}
	ft_parse_rules(argv + 1, sim);
	if (ft_init_forks(sim->num_philosophers, &sim->forks) == FAILURE)
		return (FAILURE);
	if (ft_init_philosophers(sim) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
