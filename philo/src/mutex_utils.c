/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:18:47 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/09 20:56:01 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

int	ft_init_mutex(t_simulation *s, pthread_mutex_t *mtx, char *fun)
{
	int	res;

	res = pthread_mutex_init(mtx, NULL);
	if (res != SUCCESS)
	{
		ft_put_error(s, fun, ERR_MUTEX_INIT);
		ft_set_running(s, FALSE);
	}
	return (res);
}

int	ft_destroy_mutex(t_simulation *s, pthread_mutex_t *mtx, char *fun)
{
	int	res;

	res = pthread_mutex_destroy(mtx);
	if (res != SUCCESS)
	{
		ft_put_error(s, fun, ERR_MUTEX_DESTROY);
		ft_set_running(s, FALSE);
	}
	return (res);
}

int	ft_lock_mutex(t_simulation *s, pthread_mutex_t *mtx, char *fun)
{
	int	res;

	res = pthread_mutex_lock(mtx);
	if (res != SUCCESS)
	{
		ft_put_error(s, fun, ERR_MUTEX_LOCK);
		ft_set_running(s, FALSE);
	}
	return (res);
}

int	ft_unlock_mutex(t_simulation *s, pthread_mutex_t *mtx, char *fun)
{
	int	res;

	res = pthread_mutex_unlock(mtx);
	if (res != SUCCESS)
	{
		ft_put_error(s, fun, ERR_MUTEX_UNLOCK);
		ft_set_running(s, FALSE);
	}
	return (res);
}
