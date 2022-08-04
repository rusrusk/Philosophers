/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:56:11 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/04 10:13:53 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Checks if any philo died
 * 
 * @param monitor 
 * @return int 
 */
void	*check_for_death(void *philo_check)
{
	t_philo		*philo;
	t_data		*data;
	long long	time_without_eating;
	int			die;

	die = 0;
	philo = (t_philo *)philo_check;
	data = philo->data;
	while (!die)
	{
		pthread_mutex_lock(&(philo->check_philo_died));
		time_without_eating = curr_time_millisec() - philo->last_meal_time;
		if (time_without_eating > data->time_to_die && die == 0)
		{
			print_message(data, philo->idx, "died");
			pthread_mutex_lock(&(data->stop_mutex));
			data->stop = 1;
			pthread_mutex_unlock(&(data->stop_mutex));
			die = 1;
			pthread_mutex_unlock(&(philo->check_philo_died));
			break ;
		}
		pthread_mutex_unlock(&(philo->check_philo_died));
	}
	return (NULL);
}

void	*check_amount_of_meal(void *philo_check)
{
	t_data	*data;

	data = (t_data *)philo_check;
	while (1)
	{
		pthread_mutex_lock(&data->stop_mutex);
		if ((data->nb_meals_stop_philo == data->nb_of_philos) \
			|| data->stop == 1)
		{
			data->stop = 1;
			pthread_mutex_unlock(&data->stop_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->stop_mutex);
	}
	return (NULL);
}
