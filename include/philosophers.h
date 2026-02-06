/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:20:20 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/06 12:59:45 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

// -------------------------------- FUNCTIONS ------------------------------- //

int		ft_parse(int n_args, char **args, t_data *dt);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_puterror(char *msg);

// ------------------------------- STRUCTURES ------------------------------- //

// typedef struct	s_lifetime
// {
// 	int	status;
// 	int	born_at;
// 	int	died_at;
// }	t_lifetime;

// typedef struct	s_philosopher
// {
// 	int	id;
// 	int	hands[2];

// }	t_philosopher;

typedef struct s_table
{
	pthread_t	*threads;
	int			*forks;
}	t_table;

typedef struct s_data
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	t_table	*table;
}	t_data;

// --------------------------------- MACROS --------------------------------- //

# define ERR_MISS_ARGS "Error: missing arguments.\n"

#endif