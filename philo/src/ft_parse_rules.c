/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:32:56 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/09 22:49:35 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

static void	ft_put_inv_input_error(t_simulation *sim, char *arg)
{
	int	res;

	res = ft_lock_mutex(sim, &sim->print_lock, "ft_put_inv_input_error()");
	if (res != SUCCESS)
		return ;
	printf("%s: invalid argument: '%s' — expected positive integer\n",
		ERR_PREFIX, arg);
	ft_unlock_mutex(sim, &sim->print_lock, "ft_put_inv_input_error()");
}

static t_result	ft_validate_argc(t_simulation *sim, int argc)
{
	if (argc < 5)
	{
		ft_put_error(sim, NULL, ERR_MISS_ARGS);
		return (FAILURE);
	}
	else if (argc > 6)
	{
		ft_put_error(sim, NULL, ERR_MANY_ARGS);
		return (FAILURE);
	}
	return (SUCCESS);
}

static t_result	ft_validate_arg(t_simulation *sim, char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (ft_is_digit(arg[i]) == FALSE)
		{
			ft_put_inv_input_error(sim, arg);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

static t_result	ft_validate_argv(t_simulation *sim, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_validate_arg(sim, argv[i]) != SUCCESS)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

t_result	ft_parse_rules(int argc, char **argv, t_simulation *sim)
{
	if (ft_validate_argc(sim, argc) != SUCCESS)
		return (FAILURE);
	if (ft_validate_argv(sim, argv) != SUCCESS)
		return (FAILURE);
	sim->philo_count = ft_atol(argv[1]);
	sim->time_to_die = ft_atol(argv[2]);
	sim->time_to_eat = ft_atol(argv[3]);
	sim->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		sim->meals_counter_target = ft_atol(argv[5]);
	else
		sim->meals_counter_target = -1;
	return (SUCCESS);
}
