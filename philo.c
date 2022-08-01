/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:02:40 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/01 18:51:49 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_data *data)
{
	int			i;
	pthread_t	thread;

	i = 0;
	data->start_time = curr_time_millisec();
	while (i < data->nb_of_philos)
	{
		if (pthread_create(&data->philo[i].thread, NULL, \
			&cycle, &data->philo[i]) == ERROR)
			return (ERROR);
		if (pthread_create(&thread, NULL, \
			&check_for_death, &data->philo[i]) == ERROR)
			return (ERROR);
		pthread_detach(thread);
		++i;
	}
	if (data->nb_must_be_eaten != 0)
	{
		if (pthread_create(&thread, NULL, &check_amount_of_meal, data) == ERROR)
			return (ERROR);
		pthread_detach(thread);
	}
	return (SUCCESS);
}

int	join_and_destroy_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philos)
	{
		if (pthread_join(data->philo[i].thread, NULL) == ERROR)
			return (ERROR);
		if (pthread_mutex_destroy(&(data->philo[i++].check_philo_died)) \
			== ERROR)
			return (ERROR);
	}
	free(data->philo);
	i = 0;
	while (i < data->nb_of_philos)
		pthread_mutex_destroy(&data->forks[i++]);
	free(data->forks);
	return (SUCCESS);
}