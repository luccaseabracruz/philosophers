/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_running.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:31:24 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/09 20:47:58 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	ft_set_running(t_simulation *sim, t_bool value)
{
	if (ft_lock_mutex(sim, &sim->running_lock, "ft_set_running()") != SUCCESS)
		return ;
	sim->running = value;
	ft_unlock_mutex(sim, &sim->running_lock, "ft_set_running()");
}

t_bool	ft_is_running(t_simulation *sim)
{
	int	res;

	res = ft_lock_mutex(sim, &sim->running_lock, "ft_is_running()");
	if (res != SUCCESS)
		return (FALSE);
	if (sim->running == FALSE)
	{
		ft_unlock_mutex(sim, &sim->running_lock, "ft_is_running()");
		return (FALSE);
	}
	res = ft_unlock_mutex(sim, &sim->running_lock, "ft_is_running()");
	if (res != SUCCESS)
		return (FALSE);
	return (TRUE);
}
