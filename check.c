/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:56:11 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/01 18:51:05 by rkultaev         ###   ########.fr       */
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
		// printf("time: %lld\n", philo->last_meal_time);
		if (time_without_eating > data->time_to_die && die == 0)
		{
			print_message(philo->data, philo->idx, "is died");
			// pthread_mutex_lock(&(philo->check_philo_died));
			pthread_mutex_lock(&(data->stop_mutex));
			data->stop = 1;
			pthread_mutex_unlock(&(data->stop_mutex));
			die = 1;
			// pthread_mutex_unlock(&(philo->check_philo_died));
		}
		// pthread_mutex_unlock(&(data->stop_mutex));
		pthread_mutex_unlock(&(philo->check_philo_died));
	}
	return (NULL);
}

void	*check_amount_of_meal(void *philo_check)
{
	t_data	*data;
	// t_philo	*philo;
	data = (t_data *) philo_check;
	// data = philo->data;
	while (!data->stop)
	{
		pthread_mutex_lock(&data->stop_mutex);
		if (data->nb_meals_stop_philo == data->nb_of_philos)
			data->stop = 1;
		pthread_mutex_unlock(&data->stop_mutex);
		// pthread_mutex_unlock(&data->stop_mutex);
	}
	
	// printf ("%d\n", data->nb_meals_stop_philo);
	return (NULL);
}
