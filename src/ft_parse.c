/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:58:23 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/06 12:59:15 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

int	ft_parse(int n_args, char **args, t_data *dt)
{
	if (n_args < 4)
	{
		ft_puterror(ERR_MISS_ARGS);
		return (EXIT_FAILURE);
	}
	dt->number_of_philosophers = ft_atoi(args[0]);
	dt->time_to_die = ft_atoi(args[1]);
	dt->time_to_eat = ft_atoi(args[2]);
	dt->time_to_sleep = ft_atoi(args[3]);
	if (args[4])
		dt->number_of_times_each_philosopher_must_eat = ft_atoi(args[4]);
	else
		dt->number_of_times_each_philosopher_must_eat = -1;
	return (EXIT_SUCCESS);
}
