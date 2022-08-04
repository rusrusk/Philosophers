/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:17:00 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/04 10:07:43 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief function checks for digits
 * 
 * @param argv 
 * @return int 
 */
int	digit_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < 48 || argv[i][j] > 57))
				return (ERROR);
		j++;
		}
	i++;
	}
	return (SUCCESS);
}

/**
 * @brief Parses the program arguments
 * 
 * @param argc 
 * @param argv 
 * @param data 
 * @return int 
 */
int	check_args(int argc, char **argv, t_data *data)
{	
	if ((argc == 5 || argc == 6))
	{
		data->nb_of_philos = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data->nb_must_be_eaten = ft_atoi(argv[5]);
		else
			data->nb_must_be_eaten = -1;
		return (SUCCESS);
	}
	return (ERROR);
}
