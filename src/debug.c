/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:57:47 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/06 17:38:22 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

void	ft_print_simulation(t_simulation *sim)
{
	printf("----------------------------------------------------\n");
	printf("data:\n");
	printf("	- number of philosophers: %d\n", sim->num_philosophers);
	printf("	- time to die: %d\n", sim->time_to_die);
	printf("	- time to eat: %d\n", sim->time_to_eat);
	printf("	- time to sleep: %d\n", sim->time_to_sleep);
	if (sim->meals_counter_target >= 0)
	{
		printf("	- number of times each philosopher must eat: %d\n",
			sim->meals_counter_target);
	}
	printf("----------------------------------------------------\n");
}
