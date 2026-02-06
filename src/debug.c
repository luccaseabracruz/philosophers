/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:57:47 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/06 13:03:10 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

void	ft_print_data(t_data *dt)
{
	printf("----------------------------------------------------\n");
	printf("data:\n");
	printf("	- number of philosophers: %d\n", dt->number_of_philosophers);
	printf("	- time to die: %d\n", dt->time_to_die);
	printf("	- time to eat: %d\n", dt->time_to_eat);
	printf("	- time to sleep: %d\n", dt->time_to_sleep);
	if (dt->number_of_times_each_philosopher_must_eat >= 0)
	{
		printf("	- number of times each philosopher must eat: %d\n",
			dt->number_of_times_each_philosopher_must_eat);
	}
	printf("----------------------------------------------------\n");
}
