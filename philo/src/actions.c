/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 11:15:26 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/09 20:56:51 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	ft_take_fork(t_philosopher *philo, t_fork_side side)
{
	pthread_mutex_t	*fork;
	int				res;

	if (side == RIGHT)
		fork = philo->right_fork;
	else if (side == LEFT)
		fork = philo->left_fork;
	else
		fork = philo->right_fork;
	res = ft_lock_mutex(philo->sim, fork, "ft_take_fork()");
	if (res != SUCCESS)
		return ;
	if (ft_is_running(philo->sim) == FALSE)
		return ;
	ft_print_action(philo, MSG_FORK, NULL);
}

void	ft_release_forks(t_philosopher *philo)
{
	ft_unlock_mutex(philo->sim, philo->left_fork, "ft_release_forks()");
	ft_unlock_mutex(philo->sim, philo->right_fork, "ft_release_forks()");
}

void	ft_eat(t_philosopher *philo)
{
	if (ft_is_running(philo->sim) == FALSE)
		return ;
	philo->last_meal = ft_get_timestamp(MILISECONDS);
	ft_print_action(philo, MSG_EAT, &philo->last_meal);
	philo->meals_counter++;
	ft_safe_usleep(philo->sim, philo->sim->time_to_eat);
}

void	ft_sleep(t_philosopher *philo)
{
	if (ft_is_running(philo->sim) == FALSE)
		return ;
	ft_print_action(philo, MSG_SLEEP, NULL);
	ft_safe_usleep(philo->sim, philo->sim->time_to_sleep);
}

void	ft_think(t_philosopher *philo)
{
	if (ft_is_running(philo->sim) == FALSE)
		return ;
	ft_print_action(philo, MSG_THINK, NULL);
}
