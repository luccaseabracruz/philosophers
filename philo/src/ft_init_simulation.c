/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:58:23 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/19 10:27:45 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

static t_result	ft_init_forks(t_simulation *sim)
{
	int	i;

	sim->forks = malloc(sim->philo_count * sizeof(pthread_mutex_t));
	if (!sim->forks)
	{
		ft_put_error(&sim->print_lock, "ft_init_forks()", ERR_MALLOC);
		return (FAILURE);
	}
	i = 0;
	while (i < sim->philo_count)
	{
		pthread_mutex_init(sim->forks + i, NULL);
		i++;
	}
	return (SUCCESS);
}

static void	ft_assign_forks(t_philosopher *philo)
{
	pthread_mutex_t	*forks;
	int				philo_count;
	int				i;

	forks = philo->sim->forks;
	philo_count = philo->sim->philo_count;
	i = philo->id - 1;
	philo->right_fork = forks + i;
	philo->left_fork = forks + ((i + 1) % philo_count);
}

static t_result	ft_init_philosophers(t_simulation *sim)
{
	t_philosopher	*philos;
	int				i;

	sim->philos = malloc(sim->philo_count * sizeof(t_philosopher));
	if (!sim->philos)
	{
		ft_put_error(&sim->print_lock, "ft_init_philosophers()", ERR_MALLOC);
		return (FAILURE);
	}
	philos = sim->philos;
	memset(philos, 0, sim->philo_count * sizeof(t_philosopher));
	i = 0;
	while (i < sim->philo_count)
	{
		philos[i].id = i + 1;
		philos[i].sim = sim;
		philos[i].last_meal = ft_get_timestamp(MILISECONDS);
		ft_assign_forks(philos + i);
		i++;
	}
	return (SUCCESS);
}

t_result	ft_init_simulation(int argc, char **argv, t_simulation *sim)
{
	if (ft_parse_rules(argc, argv, sim) != SUCCESS)
		return (FAILURE);
	if (ft_init_forks(sim) != SUCCESS)
		return (FAILURE);
	if (pthread_mutex_init(&sim->print_lock, NULL) != SUCCESS)
	{
		ft_cleanup_forks(sim->forks, sim->philo_count);
		return (FAILURE);
	}
	if (pthread_mutex_init(&sim->running_lock, NULL))
	{
		ft_cleanup_forks(sim->forks, sim->philo_count);
		pthread_mutex_destroy(&sim->print_lock);
		return (FAILURE);
	}
	if (ft_init_philosophers(sim) != SUCCESS)
	{
		ft_cleanup_forks(sim->forks, sim->philo_count);
		pthread_mutex_destroy(&sim->print_lock);
		pthread_mutex_destroy(&sim->running_lock);
		return (FAILURE);
	}
	return (SUCCESS);
}
