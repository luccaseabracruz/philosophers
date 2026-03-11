/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:05:04 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/11 10:15:01 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "philosophers.h"

typedef struct s_philosopher
{
	int				id;
	int				meals_counter;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_simulation	*sim;
}	t_philosopher;

typedef struct s_simulation
{
	long			philo_count;
	long			start_timestamp;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals_counter_target;
	t_philosopher	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	running_lock;
	pthread_t		monitoring_thread;
	t_bool			running;
}	t_simulation;

#endif