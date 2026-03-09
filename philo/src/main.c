/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:39:46 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/04 16:23:16 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	t_simulation	sim;

	memset(&sim, 0, sizeof(sim));
	if (ft_init_simulation(argc, argv, &sim) == FAILURE)
		return (EXIT_FAILURE);
	if (ft_start_simulation(&sim) == FAILURE)
	{
		ft_cleanup_simulation(&sim);
		return (EXIT_FAILURE);
	}
	ft_cleanup_simulation(&sim);
	return (EXIT_SUCCESS);
}
