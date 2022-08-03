/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:37:04 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/03 11:51:23 by rkultaev         ###   ########.fr       */
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
