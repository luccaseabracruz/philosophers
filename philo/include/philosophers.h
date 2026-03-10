/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:20:20 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/10 16:33:16 by lseabra-         ###   ########.fr       */
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
int			ft_is_digit(char c);
t_result	ft_safe_atol(char *str, long *num_addr);
void		ft_cleanup_forks(t_simulation *sim);
void		ft_cleanup_simulation(t_simulation *sim);
long		ft_get_timestamp(t_sec_unit unit);
t_result	ft_init_simulation(int argc, char **argv, t_simulation *sim);
void		ft_set_running(t_simulation *sim, t_bool value);
t_bool		ft_is_running(t_simulation *sim);
void		*ft_monitoring_routine(void *arg);
t_result	ft_parse_rules(int argc, char **argv, t_simulation *sim);
void		*ft_routine(void *arg);
void		ft_safe_usleep(t_simulation *sim, long time_ms);
t_result	ft_start_simulation(t_simulation *sim);
int			ft_init_mutex(t_simulation *s, pthread_mutex_t *mtx, char *fun);
int			ft_destroy_mutex(t_simulation *s, pthread_mutex_t *mtx, char *fun);
int			ft_lock_mutex(t_simulation *s, pthread_mutex_t *mtx, char *fun);
int			ft_unlock_mutex(t_simulation *s, pthread_mutex_t *mtx, char *fun);
void		ft_put_str_fd(int fd, char *str);
void		ft_put_error(t_simulation *sim, char *function, char *message);
void		ft_print_action(t_philosopher *philo, char *msg, long *timestamp);

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

// --------------------------------- MACROS --------------------------------- //

# define ERR_PRINT_LOCK_INIT	"ERROR: print_lock mutex init fail\n"
# define ERR_PRINT_LOCK_LOCK	"ERROR: print_lock mutex lock failed\n"
# define ERR_PRINT_LOCK_UNLOCK	"ERROR: print_lock mutex unlock failed\n"
# define ERR_ATOL_INV_INPUT		"ERROR: invalid input\n"
# define ERR_LONG_RANGE			"ERROR: input value out of LONG range\n"

# define ERR_PREFIX			"ERROR"
# define ERR_MISS_ARGS		"missing arguments"
# define ERR_MANY_ARGS		"too many arguments"
# define ERR_INV_INPUT		"invalid input"
# define ERR_MALLOC			"malloc fail ocurred"
# define ERR_THREAD_CREATE	"thread creation fail"
# define ERR_THREAD_JOIN	"thread join fail"
# define ERR_MUTEX_INIT		"mutex init fail"
# define ERR_MUTEX_DESTROY	"mutex destroy fail"
# define ERR_MUTEX_LOCK		"mutex lock fail"
# define ERR_MUTEX_UNLOCK	"mutex unlock fail"

# define MSG_FORK	"has taken a fork"
# define MSG_EAT	"is eating"
# define MSG_SLEEP	"is sleeping"
# define MSG_THINK	"is thinking"
# define MSG_DIE	"died"

# define MONITORING_INTERVAL_MS 1

# define ORANGE	"\033[38;5;208m"
# define BLUE	"\033[34m"
# define TEAL	"\033[36m"
# define RESET	"\033[0m"

#endif