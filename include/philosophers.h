/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:20:20 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/10 16:50:50 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

typedef struct s_simulation	t_simulation;

// -------------------------------- FUNCTIONS ------------------------------- //

int		ft_init_simulation(int argc, char **argv, t_simulation *sim);
void	*ft_routine(void *arg);
int		ft_start_simulation(t_simulation *sim);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_puterror(char *msg);

// ------------------------------- STRUCTURES ------------------------------- //

typedef struct s_philosopher
{
	int				id;
	int				meals_counter;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_simulation	*sim;
}	t_philosopher;

typedef struct s_simulation
{
	int				running;
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_counter_target;
	long			start_time_stamp;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
}	t_simulation;

// --------------------------------- MACROS --------------------------------- //

# define ERR_MISS_ARGS		"Error: missing arguments.\n"
# define ERR_MALLOC			"Error: malloc fail ocurred.\n"
# define ERR_THREAD_CREATE	"Error: thread creation fail.\n"
# define ERR_THREAD_JOIN	"Error: thread join fail.\n"

# define MSG_FORK	"has taken a fork"
# define MSG_EAT	"is eating"
# define MSG_SLEEP	"is sleeping"
# define MSG_THINK	"is thinking"
# define MSG_DIE	"died"

# define SUCCESS	0
# define FAILURE	-1

#endif