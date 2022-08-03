/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:37:04 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/03 23:44:41 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_data *data, int idx, char *msg)
{
	long long	time_work;

	pthread_mutex_lock(&(data->stop_mutex));
	// pthread_mutex_lock(&(data->print));
	time_work = curr_time_millisec() - data->start_time;
	if (!data->stop)
	{
		printf("%lld\t%d\t%s\n", time_work, idx, msg);
	}	
		pthread_mutex_unlock(&(data->stop_mutex));
	// pthread_mutex_unlock(&(data->print));
}

int handle_one_philo(t_data *data)
{
	long long time;

	time = curr_time_millisec() - data->start_time;
	printf("%lld %d %s\n", curr_time_millisec() - time, data->philo->idx, "has taken a fork");
	usleep(data->time_to_die * 1000);
	printf("%lld %d %s\n", curr_time_millisec() - time, data->philo->idx, "has died");
	return (ERROR);
}
