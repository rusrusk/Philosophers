/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:57:30 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/04 16:44:25 by rkultaev         ###   ########.fr       */
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
