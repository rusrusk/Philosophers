/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:10:19 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/04 10:11:12 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	conversion(const char *str, int plus_minus, int i)
{
	long int	nb;

	nb = 0;
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		if (nb > 2147483648 && plus_minus == -1)
			return (0);
		if (nb > 2147483647 && plus_minus == 1)
			return (-1);
			nb = nb * 10 + str[i] - 48;
			i++;
	}
	return (nb);
}

int	ft_atoi(const char *str)
{
	int				plus_minus;
	int				i;
	long int		value;

	value = 0;
	i = 0;
	plus_minus = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
				plus_minus = -1;
		}
		i++;
	}
	value = conversion(str, plus_minus, i);
	return (value * plus_minus);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write (fd, s, ft_strlen(s));
	exit(ERROR);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	while (s[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write (fd, s, ft_strlen(s));
	write (fd, "\n", 1);
}
