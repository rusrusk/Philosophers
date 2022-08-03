/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:57:30 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/01 11:25:34 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Returns time in milliseconds
 * 
 * @return long long 
 */
long long	curr_time_millisec(void)
{
	long long			millisec_time_interval;
	long long			seconds;
	long long			microseconds;
	struct timeval		now;

	if (gettimeofday(&now, NULL) == ERROR)
		return (ERROR);
	seconds = now.tv_sec * 1000;
	microseconds = now.tv_usec / 1000;
	millisec_time_interval = seconds + microseconds;
	return (millisec_time_interval);
}

// long long	time_to_ms(struct timeval now)
// {
// 	long long		ms;

// 	ms = now.tv_sec * 1000;
// 	ms += now.tv_usec / 1000;
// 	return (ms);
// }

// int	elapsed_time(t_data *info)
// {
// 	return (curr_time_millisec() - info->start_time);
// }

// long long	ft_current_time(void)
// {
// 	struct timeval	current_time;
// 	long long		ms;

// 	gettimeofday(&current_time, NULL);
// 	ms = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
// 	return (ms);
// }