/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:20:20 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/19 14:56:37 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

typedef struct s_simulation		t_simulation;
typedef struct s_philosopher	t_philosopher;

typedef enum e_bool				t_bool;
typedef enum e_result			t_result;
typedef enum e_sec_unit			t_sec_unit;
typedef enum e_fork_side		t_fork_side;

// -------------------------------- FUNCTIONS ------------------------------- //

void		ft_take_fork(t_philosopher *philo, t_fork_side side);
void		ft_release_forks(t_philosopher *philo);
void		ft_eat(t_philosopher *philo);
void		ft_sleep(t_philosopher *philo);
void		ft_think(t_philosopher *philo);
void		ft_cleanup_forks(pthread_mutex_t *forks, int philo_count);
void		ft_cleanup_simulation(t_simulation *sim);
long		ft_get_timestamp(t_sec_unit unit);
t_result	ft_init_simulation(int argc, char **argv, t_simulation *sim);
void		ft_set_running(t_simulation *sim, t_bool value);
t_bool		ft_is_running(t_simulation *sim);
void		*ft_monitoring_routine(void *arg);
t_result	ft_parse_rules(int argc, char **argv, t_simulation *sim);
void		*ft_routine(void *arg);
t_result	ft_start_simulation(t_simulation *sim);
long		ft_atol(char *str);
void		ft_put_error(pthread_mutex_t *lock, char *function, char *message);
void		ft_put_msg(t_philosopher *philo, char *msg, long *timestamp);

// ------------------------------- ENUMS ------------------------------- //

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef enum e_result
{
	FAILURE = -1,
	SUCCESS = 0
}	t_result;

typedef enum e_sec_unit
{
	SECONDS,
	MILISECONDS,
	MICROSECONDS,
}	t_sec_unit;

typedef enum e_fork_side
{
	RIGHT,
	LEFT
}	t_fork_side;

// ------------------------------- STRUCTURES ------------------------------- //

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
	int				philo_count;
	long			start_timestamp;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				meals_counter_target;
	t_philosopher	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	running_lock;
	pthread_t		monitoring_thread;
	t_bool			running;
}	t_simulation;

// --------------------------------- MACROS --------------------------------- //

# define ERR_PREFIX			"ERROR"
# define ERR_MISS_ARGS		"missing arguments"
# define ERR_MANY_ARGS		"too many arguments"
# define ERR_NEG_NUM		"negative numbers are not permitted"
# define ERR_MALLOC			"malloc fail ocurred"
# define ERR_THREAD_CREATE	"thread creation fail"
# define ERR_THREAD_JOIN	"thread join fail"

# define MSG_FORK	"has taken a fork"
# define MSG_EAT	"is eating"
# define MSG_SLEEP	"is sleeping"
# define MSG_THINK	"is thinking"
# define MSG_DIE	"died"

# define MONITORING_INTERVAL_MS 1

#endif