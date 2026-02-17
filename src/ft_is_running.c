/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_running.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:31:24 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/16 17:58:31 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	ft_set_running(t_simulation *sim, t_bool value)
{
	pthread_mutex_lock(&sim->running_lock);
	sim->running = value;
	pthread_mutex_unlock(&sim->running_lock);
}

t_bool	ft_is_running(t_simulation *sim)
{
	pthread_mutex_lock(&sim->running_lock);
	if (sim->running == FALSE)
	{
		pthread_mutex_unlock(&sim->running_lock);
		return (FALSE);
	}
	pthread_mutex_unlock(&sim->running_lock);
	return (TRUE);
}