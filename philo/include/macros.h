/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:04:10 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/11 10:04:40 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define ERR_PRINT_LOCK_INIT	"ERROR: print_lock mutex init fail\n"
# define ERR_PRINT_LOCK_LOCK	"ERROR: print_lock mutex lock failed\n"
# define ERR_PRINT_LOCK_UNLOCK	"ERROR: print_lock mutex unlock failed\n"
# define ERR_ATOL_INV_INPUT		"ERROR: invalid input\n"
# define ERR_LONG_RANGE			"ERROR: input value out of LONG range\n"

# define ERR_PREFIX			"ERROR"
# define ERR_MISS_ARGS		"missing arguments"
# define ERR_MANY_ARGS		"too many arguments"
# define ERR_INV_INPUT		"invalid input"
# define ERR_MALLOC			"malloc fail ocurred"
# define ERR_THREAD_CREATE	"thread creation fail"
# define ERR_THREAD_JOIN	"thread join fail"
# define ERR_MUTEX_INIT		"mutex init fail"
# define ERR_MUTEX_DESTROY	"mutex destroy fail"
# define ERR_MUTEX_LOCK		"mutex lock fail"
# define ERR_MUTEX_UNLOCK	"mutex unlock fail"

# define MSG_TAKE_FORK	"has taken a fork"
# define MSG_EAT		"is eating"
# define MSG_SLEEP		"is sleeping"
# define MSG_THINK		"is thinking"
# define MSG_DIE		"died"

# define MONITORING_INTERVAL_MS 1

# define GRAY	"\033[38;5;240m"
# define WHITE	"\033[38;5;255m"
# define AMBER	"\033[38;5;214m"
# define PURPLE	"\033[38;5;99m"
# define SKY_BLUE	"\033[38;5;75m"
# define NEON_GREEN	"\033[38;5;48m"
# define RED	"\033[38;5;196m"
# define RESET	"\033[0m"

#endif