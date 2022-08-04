/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:37:04 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/04 16:48:57 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_message(t_data *data, int idx, char *msg)
{
	long long	time_work;

	if (pthread_mutex_lock(&(data->stop_mutex)) == ERROR)
		return (MUTEX_LOCK_ERROR);
	time_work = curr_time_millisec() - data->start_time;
	if (!data->stop)
	{
		printf("%lld %d %s\n", time_work, idx, msg);
	}	
	if (pthread_mutex_unlock(&(data->stop_mutex)) == ERROR)
		return (MUTEX_UNLOCK_ERROR);
	return (SUCCESS);
}
