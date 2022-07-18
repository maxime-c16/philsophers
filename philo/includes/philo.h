/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:36:23 by mcauchy           #+#    #+#             */
/*   Updated: 2022/06/16 09:42:02 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				last_eat;
	int				meals;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	struct s_data	*data;
	int				die_soon;
}				t_philo;

typedef struct s_data
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_philo;
	int				nb_must_eat;
	int				is_dead;
	int				time_start;
	int				has_eaten;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	is_dead_m;
	pthread_mutex_t	message;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eating;
}				t_data;

int		ft_atoi(const char *str);
int		check_args(char **av);
void	init_data(char **av, t_data *data);
void	init_fork(t_data *data);
void	init_philo(t_data *data);
void	*print_thread_id(void *philo);
void	ft_usleep(int time);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		get_time(void);
int		get_time_since_start(t_philo *philo);
void	mutex_message(char *msg, t_philo *philo);
void	*routine(void *philo);
int		is_dead(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_die(t_philo *philo);
void	philo_think(t_philo *philo);
int		kill_philo(t_philo *philo);
void	*monitoring(t_data *data);

#endif
