/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_and_structs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:17:12 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/03 09:25:46 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_AND_STRUCTS_H
# define MACROS_AND_STRUCTS_H

# define MSG_COLOR_RED		"\033[0;31m"
# define MSG_COLOR_GREEN	"\033[0;32m"
# define COLOR_YELLOW		"\033[0;33m"
# define COLOR_BLUE			"\033[0;34m"
# define MSG_COLOR_WHITE	"\033[0;37m"

enum e_return
{
	SUCCESS,
	ERROR = -1
};

typedef enum s_error
{
	MALLOC_ERROR = -1,
	MUTEX_INIT_ERROR = -1,
	MUTEX_DESTROY_ERROR,
	MUTEX_LOCK_ERROR,
	MUTEX_UNLOCK_ERROR,
	PTHREAD_CREATE_ERROR
}	t_error;

/**
 * @brief info about arguments that the user inputs
 * 
 */

typedef struct s_data
{
	int				nb_of_philos;
	int				nb_must_be_eaten;
	int				nb_meals_stop_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	long long		start_time;
	int				stop;
	char			*message[5];
	struct s_philo	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	stop_mutex;
	pthread_t		thread_for_meal;
}	t_data;

/**
 * @brief info about the each philosopher
 * 
 */
typedef struct s_philo
{
	int						idx;
	pthread_t				thread;
	pthread_t				thread_for_death;

	pthread_mutex_t			check_philo_died;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	int						nb_of_eaten_meals;
	int						time_without_eating;
	long long				last_meal_time; //current time - start time
	t_data					*data;
}	t_philo;

#endif
