/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:35:03 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/03 16:59:25 by rkultaev         ###   ########.fr       */
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
	if (create_thread(&data) == ERROR)
		return (ERROR);
	if (join_and_destroy_thread(&data) == ERROR)
		return (ERROR);
	printf("in cycle\n");
	return (SUCCESS);
}


// int	ft_error_arg(int argc)
// {
// 	if (argc > 6)
// 		write(1, "Too many arguments\n", 19);
// 	else if (argc < 5)
// 		write(1, "Too few arguments\n", 18);
// 	return (1);
// }