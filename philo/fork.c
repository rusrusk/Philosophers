/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:53:32 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/04 10:05:21 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (pthread_mutex_lock(philo->left_fork) != ERROR)
		print_message(philo->data, philo->idx, "has taken a fork");
	if (philo->data->nb_of_philos == 1)
		return (ERROR);
	if (pthread_mutex_lock(philo->right_fork) != ERROR)
		print_message(philo->data, philo->idx, "has taken a fork");
	return (SUCCESS);
}

int	drop_forks(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->left_fork) == ERROR)
		return (ERROR);
	if (pthread_mutex_unlock(philo->right_fork) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
