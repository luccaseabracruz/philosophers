/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_atol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:25:13 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/10 16:33:45 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <limits.h>
#include <unistd.h>

int	ft_is_digit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (1);
}

t_result	ft_increment_res(char cur_num, int sign, long *res)
{
	long long	temp;
	long long	limit;

	limit = LONG_MAX;
	if (sign == -1)
		limit++;
	temp = (long long)*res;
	if (temp > (limit - (cur_num - '0')) / 10)
	{
		ft_put_str_fd(STDERR_FILENO, ERR_LONG_RANGE);
		return (FAILURE);
	}
	temp = (temp * 10) + (cur_num - '0');
	*res = (long)temp;
	return (SUCCESS);
}

static t_result	ft_validate_char(char c)
{
	if (ft_is_digit(c) == FALSE)
	{
		ft_put_str_fd(STDERR_FILENO, ERR_ATOL_INV_INPUT);
		return (FAILURE);
	}
	else
		return (SUCCESS);
}

t_result	ft_safe_atol(char *str, long *num_addr)
{
	long	res;
	int		sign;
	int		i;

	if (!str || !num_addr)
		return (FAILURE);
	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_validate_char(str[i]) != SUCCESS
			|| ft_increment_res(str[i], sign, &res) != SUCCESS)
			return (FAILURE);
		i++;
	}
	*num_addr = res * sign;
	return (SUCCESS);
}
