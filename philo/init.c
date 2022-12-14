/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:25:31 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/04 14:51:05 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief allocate memory for array of t_philo
 * 
 * @param data 
 * @return t_data* 
 */
static int	fill_philo(t_data *data)
{
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nb_of_philos);
	if (data->philo == NULL)
		return (MALLOC_ERROR);
	return (SUCCESS);
}

/**
 * @brief allocate memory for array of pthread_mutex_t
 * 
 * @param data 
 * @return t_data* 
 */
static int	fill_forks(t_data *data)
{
	data->forks = malloc (sizeof(pthread_mutex_t) * data->nb_of_philos);
	if (data->forks == NULL)
		return (MALLOC_ERROR);
	return (SUCCESS);
}

/**
 * @brief Mutex constructor
 * 
 * @param data
 * @return int
 */
static int	mutex_data(t_data *data)
{
	int	i;

	i = 0;
	fill_forks(data);
	data->start_time = curr_time_millisec();
	data->stop = 0;
	data->nb_meals_stop_philo = 0;
	while (i < data->nb_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) == ERROR)
			return (MUTEX_INIT_ERROR);
		++i;
	}
	if (pthread_mutex_init(&data->stop_mutex, NULL) == ERROR)
		return (MUTEX_INIT_ERROR);
	return (SUCCESS);
}

/**
 * @brief Philosopher constructor
 * 
 * @param data
 * @return int*
 */
static int	philosophers_data(t_data *data)
{
	int			i;
	long long	t;

	i = 0;
	fill_philo(data);
	t = curr_time_millisec();
	while (i < data->nb_of_philos)
	{
		data->philo[i].nb_of_eaten_meals = 0;
		data->philo[i].data = data;
		data->philo[i].idx = i;
		data->philo[i].last_meal_time = t;
		if (i == 0)
			data->philo[i].left_fork = &(data->forks[data->nb_of_philos - 1]);
		else
			data->philo[i].left_fork = &(data->forks[i - 1]);
		data->philo[i].right_fork = &data->forks[i];
		if (pthread_mutex_init(&data->philo[i].check_philo_died, \
			NULL) == ERROR)
			return (MUTEX_INIT_ERROR);
		++i;
	}
	return (SUCCESS);
}

/**
 * @brief initializing info about threads and mutexes
 * 
 * @param data
 * @return int 
 */
int	threads_and_mutex_init(t_data *data)
{
	if (mutex_data(data) == ERROR)
		return (ERROR);
	if (philosophers_data(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
