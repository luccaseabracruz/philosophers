/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_usleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:21:00 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/23 14:31:47 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

void	ft_safe_usleep(t_simulation *sim, long time_ms)
{
	long	start;

	start = ft_get_timestamp(MILISECONDS);
	while (ft_is_running(sim)
		&& ft_get_timestamp(MILISECONDS) - start < time_ms)
	{
		usleep(1000);
	}
}
