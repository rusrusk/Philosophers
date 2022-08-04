/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:02:40 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/04 16:43:58 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_data *data)
{
	int			i;

	i = 0;
	while (i < data->nb_of_philos)
	{
		data->philo[i].last_meal_time = data->start_time;
		if (pthread_create(&data->philo[i].thread, NULL, \
			&procedure, &data->philo[i]) == ERROR)
			return (PTHREAD_CREATE_ERROR);
		if (pthread_create(&data->philo[i].thread_for_death, NULL, \
			&check_for_death, &data->philo[i]) == ERROR)
			return (PTHREAD_CREATE_ERROR);
		++i;
	}
	if (data->nb_must_be_eaten != 0)
	{
		if (pthread_create(&data->thread_for_meal, NULL, \
		check_amount_of_meal, data) == ERROR)
			return (PTHREAD_CREATE_ERROR);
	}
	return (SUCCESS);
}

static int	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philos)
	{
		if (pthread_mutex_destroy(&data->forks[i]) == ERROR)
			return (MUTEX_DESTROY_ERROR);
		if (pthread_mutex_destroy(&(data->philo[i++].check_philo_died)) \
			== ERROR)
			return (MUTEX_DESTROY_ERROR);
	}
	return (SUCCESS);
}

int	join_and_destroy_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philos)
	{
		if (pthread_join(data->philo[i].thread, NULL) == ERROR)
			return (ERROR);
		if (pthread_join(data->philo[i].thread_for_death, NULL) == ERROR)
			return (ERROR);
	++i;
	}
	if (data->nb_must_be_eaten != 0)
	{
		if (pthread_join(data->thread_for_meal, NULL) == ERROR)
			return (ERROR);
	}
	if (destroy_mutex(data) == ERROR)
		return (ERROR);
	if (pthread_mutex_destroy(&data->stop_mutex) == ERROR)
		return (MUTEX_DESTROY_ERROR);
	free(data->philo);
	free(data->forks);
	return (SUCCESS);
}
