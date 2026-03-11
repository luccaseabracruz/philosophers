/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:07:15 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/11 10:07:41 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef enum e_result
{
	FAILURE = -1,
	SUCCESS = 0
}	t_result;

typedef enum e_sec_unit
{
	SECONDS,
	MILISECONDS,
	MICROSECONDS,
}	t_sec_unit;

typedef enum e_fork_side
{
	RIGHT,
	LEFT
}	t_fork_side;

typedef enum e_action
{
	TAKE_FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_action;

#endif