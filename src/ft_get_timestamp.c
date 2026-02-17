/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_timestamp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:57:44 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/16 18:09:11 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/time.h>
#include <stddef.h>

long	ft_get_timestamp(t_sec_unit unit)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	if (unit == SECONDS)
		res = tv.tv_sec + (tv.tv_usec / 1000000);
	else if (unit == MILISECONDS)
		res = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	else if (unit == MICROSECONDS)
		res = (tv.tv_sec * 1000000) + tv.tv_usec;
	return (res);
}
