/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:15:01 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/01 10:55:37 by rkultaev         ###   ########.fr       */
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
int		check_args(int argc, char **argv, t_data *data);

int		ft_atoi(const char *str);

void	ft_putstr_fd(char *s, int fd);
int	error_message(int argc, char **argv);
size_t	ft_strlen(const char *s);
void	ft_putendl_fd(char *s, int fd);
void	error_handle(char *message);
int		ft_isdigit(int c);
int		digit_args(char **argv);

int	elapsed_time(t_data *info);
int	usleep_milliseconds(void);
long long	curr_time_millisec(void);


// int print_to_terminal(t_data *info, t_philo *philo, int msg_code);
void	print_message(t_data *data, int idx, char *msg);
char *message_content(t_data *data, int message_code);
// char **message_array(char **message);
void message_array(t_data *data);


int		threads_and_mutex_init(t_data *info);
// static int	philosophers_data(t_data *info);
int		fill_philo(t_data *data);
int		fill_mutex(t_data *data);

int		mutex_init(t_data *data);
void	mutex_destroy(t_data *data);

int	drop_forks(t_philo *philo);
int	take_forks(t_philo *philo);

void	*check_for_death(void *philo_s);
void *check_amount_of_meal(void *philo_check);

void		*cycle(void *philo_cycle);

int		create_thread(t_data *data);
int	join_and_destroy_thread(t_data *data);


#endif
