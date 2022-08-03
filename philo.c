/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:02:40 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/03 19:08:10 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_data *data)
{
	int			i;
	// pthread_t	thread;
	i = 0;
	// data->start_time = curr_time_millisec();
	
	while (i < data->nb_of_philos)
	{
		data->philo[i].last_meal_time = data->start_time;
		if (pthread_create(&data->philo[i].thread, NULL, \
			&cycle, &data->philo[i]) == ERROR)
			return (ERROR);
		
		if (pthread_create(&data->philo[i].thread_for_death, NULL, \
			&check_for_death, &data->philo[i]) == ERROR)
			return (ERROR);
		++i;
		// pthread_detach(thread);
		// i++;
	}
	
	if (data->nb_must_be_eaten != 0)
	{
		
		if (pthread_create(&data->thread_for_meal, NULL, check_amount_of_meal, data) == ERROR)
			return (ERROR);
		printf("ralf bitcoin\n");
		// pthread_detach(thread);
	}

	return (SUCCESS);
}

int	join_and_destroy_thread(t_data *data)
{
	int	i;

	i = 0;
		
	while (i < data->nb_of_philos)
	{
		// printf("nbr philo: %d\n", data->nb_of_philos);
		if (pthread_join(data->philo[i].thread, NULL) == ERROR)
			return (ERROR);
		
		if (pthread_join(data->philo[i].thread_for_death, NULL) == ERROR)
			return (ERROR);
		// printf("here\n");
			// printf("%d\n", data->nb_of_philos);
	++i;
	}

	if (data->nb_must_be_eaten != 0)
	{
		// printf("%d\n",data->nb_must_be_eaten);
			printf("after if\n");
			if (pthread_join(data->thread_for_meal, NULL) == ERROR)
				return (ERROR);
			printf("after if\n");
	}
	free(data->philo);
	printf("123\n");
	i = 0;
	printf("456\n");
	while (i < data->nb_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		if (pthread_mutex_destroy(&(data->philo[i++].check_philo_died)) == ERROR)
			return (ERROR);
	}
	printf("789\n");
	pthread_mutex_destroy(&data->stop_mutex);
	printf("abc\n");
	free(data->forks);
	printf("def\n");
	return (SUCCESS);
}
