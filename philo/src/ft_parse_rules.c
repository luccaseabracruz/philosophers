/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:32:56 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/09 16:44:45 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	else
		return (SUCCESS);
}

static t_result	ft_validate_numbers_sign(t_simulation *sim, char **argv)
{
	if (sim->philo_count < 0
		|| sim->time_to_die < 0
		|| sim->time_to_eat < 0
		|| sim->time_to_sleep < 0
		|| (argv[5] && sim->meals_counter_target < 0))
	{
		ft_put_error(sim, NULL, ERR_NEG_NUM);
		return (FAILURE);
	}
	else
		return (SUCCESS);
}

t_result	ft_parse_rules(int argc, char **argv, t_simulation *sim)
{
	if (ft_validate_argc(sim, argc) != SUCCESS)
		return (FAILURE);
	sim->philo_count = ft_atol(argv[1]);
	sim->time_to_die = ft_atol(argv[2]);
	sim->time_to_eat = ft_atol(argv[3]);
	sim->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		sim->meals_counter_target = ft_atol(argv[5]);
	else
		sim->meals_counter_target = -1;
	if (ft_validate_numbers_sign(sim, argv) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
