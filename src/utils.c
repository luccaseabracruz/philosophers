/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:24:10 by lseabra-          #+#    #+#             */
/*   Updated: 2026/02/06 12:43:07 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int	i;

// 	if (!s1 || !s2)
// 	return (0);
// 	i = 0;
// 	while (s1[i] && s2[i])
// 	i++;
// 	return (s1[i] - s2[i]);
// }

static int	ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (1);
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	if (!str)
		return (0);
	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_puterror(char *msg)
{
	int	len;

	if (msg)
	{
		len = ft_strlen(msg);
		write(STDERR_FILENO, msg, len);
	}
}
