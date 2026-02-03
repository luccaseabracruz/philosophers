/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:20:20 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/02 16:40:59 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_table
{
	t_philosopher	*participants;
	int				*forks;
}	t_table;

typedef struct	s_lifetime
{
	int	status;
	int	born_at;
	int	died_at;
}	t_lifetime;

typedef struct	s_philosopher
{
	int	id;
	int	hands[2];
	
}	t_philosopher;

#endif

#endif