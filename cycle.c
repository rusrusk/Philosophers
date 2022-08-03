/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:02:39 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/02 20:37:00 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eating_process(t_data *data, t_philo *philo)
{
	long long ms;

	pthread_mutex_lock(&(philo->check_philo_died));
	philo->last_meal_time = curr_time_millisec();
	ms = curr_time_millisec() - philo->data->start_time;
	pthread_mutex_lock(&(data->stop_mutex));
	if (!philo->data->stop)
	{
		printf("%lld\t%d\t%s\n", ms, philo->idx, "is eating");
	}
	philo->nb_of_eaten_meals += 1;
	if (data->nb_must_be_eaten != -1 && \
		philo->nb_of_eaten_meals == data->nb_must_be_eaten)
		philo->data->nb_meals_stop_philo += 1;
	// printf("%d\n", philo->data->nb_meals_stop_philo);
	pthread_mutex_unlock(&(data->stop_mutex));
	usleep(philo->data->time_to_eat * 1000);
	drop_forks(philo);
	pthread_mutex_unlock(&(philo->check_philo_died));
 	return (SUCCESS);
}

static int	sleeping_process(t_data *data, t_philo *philo)
{
	print_message(philo->data, philo->idx, "is sleeping");
	usleep(data->time_to_sleep * 1000);
	return (SUCCESS);
}

static int	thinking_process(t_philo *philo)
{
	print_message(philo->data, philo->idx, "is thinking");
	return (SUCCESS);
}

void	*cycle(void *philo_cycle)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philo_cycle;
	data = philo->data;
	if (philo->idx % 2 == 0)
		usleep(philo->data->time_to_eat * 1000);
	while (1)
	{
		pthread_mutex_lock(&(data->stop_mutex));
		if (data->stop)
		{
			// printf("%d\n", data->stop);
			pthread_mutex_unlock(&(data->stop_mutex));
			break;
		}
		pthread_mutex_unlock(&(data->stop_mutex));
		take_forks(philo);
		eating_process(philo->data, philo);
		sleeping_process(philo->data, philo);
		thinking_process(philo);
	}
	return (NULL);
}
