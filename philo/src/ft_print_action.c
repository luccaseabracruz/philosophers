/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:53:49 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/10 21:31:25 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

static char	*ft_get_color(t_action action)
{
	if (action == TAKE_FORK)
		return ((char *)NEON_GREEN);
	else if (action == EAT)
		return ((char *)AMBER);
	else if (action == SLEEP)
		return ((char *)PURPLE);
	else if (action == THINK)
		return ((char *)SKY_BLUE);
	else if (action == DIE)
		return ((char *)RED);
	else
		return ((char *)RESET);
}

static char	*ft_get_message(t_action action)
{
	if (action == TAKE_FORK)
		return ((char *)MSG_TAKE_FORK);
	else if (action == EAT)
		return ((char *)MSG_EAT);
	else if (action == SLEEP)
		return ((char *)MSG_SLEEP);
	else if (action == THINK)
		return ((char *)MSG_THINK);
	else if (action == DIE)
		return ((char *)MSG_DIE);
	else
		return ("");
}

void	ft_print_action(t_philosopher *p, t_action action, long *timestamp)
{
	long	temp;
	long	start;
	long	last_numbers;
	int		res;

	if (!p)
		return ;
	start = p->sim->start_timestamp;
	if (!timestamp)
	{
		temp = ft_get_timestamp(MILISECONDS);
		timestamp = &temp;
	}
	last_numbers = (*timestamp - start) % 1000;
	res = ft_lock_mutex(p->sim, &p->sim->print_lock, "ft_print_action()");
	if (res != SUCCESS)
		return ;
	if (ft_is_running(p->sim))
	{
		printf(GRAY"%03ld "WHITE"%d %s%s\n"RESET,
			last_numbers, p->id, ft_get_color(action), ft_get_message(action));
	}
	ft_unlock_mutex(p->sim, &p->sim->print_lock, "ft_print_action()");
}
