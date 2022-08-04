/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:15:01 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/04 16:45:41 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <errno.h>
# include <semaphore.h>
# include <stdio.h>
# include <sys/time.h>

# include "macros_and_structs.h"

/*
check arguments
*/
int			check_args(int argc, char **argv, t_data *data);
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
void		ft_putendl_fd(char *s, int fd);
int			ft_isdigit(int c);
int			digit_args(char **argv);

/*
error functions
*/
int			error_message(int argc, char **argv);
void		error_handle(char *message);
/*

time functions
*/
long long	curr_time_millisec(void);

/*
print functions
*/
int			print_message(t_data *data, int idx, char *msg);

/*
philos and forks allocation and initialization
*/
int			threads_and_mutex_init(t_data *data);
int			mutex_init(t_data *data);

/*
left and right fork mutexes
*/
int			drop_forks(t_philo *philo);
int			take_forks(t_philo *philo);

/*
checking philo death and check how many meals they ate
*/
void		*check_for_death(void *philo_s);
void		*check_amount_of_meal(void *philo_check);

/*
philo routine
*/
void		*procedure(void *philo_cycle);

/*
thread creation,joining and destroying
*/
int			create_threads(t_data *data);
int			join_and_destroy_threads(t_data *data);

#endif
