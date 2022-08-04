/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:35:03 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/04 16:44:51 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (error_message(argc, argv) == ERROR)
		return (ERROR);
	if (check_args(argc, argv, &data) == ERROR)
		return (ERROR);
	if (threads_and_mutex_init(&data) == ERROR)
		return (ERROR);
	if (create_threads(&data) == ERROR)
		return (ERROR);
	if (join_and_destroy_threads(&data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
