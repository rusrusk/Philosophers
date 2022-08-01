/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:52:17 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/01 10:53:04 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(int argc, char **argv)
{
	if ((argc < 5 || argc > 6))
	{
		ft_putstr_fd("invalid number of arguments!\n", STDOUT_FILENO);
	}
	if (digit_args(argv) == ERROR)
	{
		ft_putstr_fd("error! The input is not a number!\n", STDOUT_FILENO);
	}
	return (SUCCESS);
}

void	error_handle(char *message)
{
	ft_putendl_fd(message, 2);
}
