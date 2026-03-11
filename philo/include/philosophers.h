/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:20:20 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/11 10:08:14 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "enums.h"
# include "macros.h"
# include "structs.h"
# include <pthread.h>

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
void		ft_print_action(t_philosopher *p, t_action action, long *timestamp);
void		*ft_routine(void *arg);
void		ft_safe_usleep(t_simulation *sim, long time_ms);
t_result	ft_start_simulation(t_simulation *sim);
int			ft_init_mutex(t_simulation *s, pthread_mutex_t *mtx, char *fun);
int			ft_destroy_mutex(t_simulation *s, pthread_mutex_t *mtx, char *fun);
int			ft_lock_mutex(t_simulation *s, pthread_mutex_t *mtx, char *fun);
int			ft_unlock_mutex(t_simulation *s, pthread_mutex_t *mtx, char *fun);
void		ft_put_str_fd(int fd, char *str);
void		ft_put_error(t_simulation *sim, char *function, char *message);

#endif