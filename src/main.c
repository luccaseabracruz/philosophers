/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:39:46 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/10 16:51:17 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "debug.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_simulation	sim;

	memset(&sim, 0, sizeof(sim));
	if (ft_init_simulation(argc, argv, &sim) == FAILURE)
		return (EXIT_FAILURE);
	if (ft_start_simulation(&sim))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
