/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:40:02 by mcauchy           #+#    #+#             */
/*   Updated: 2022/06/16 09:44:37 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	assign_forks_to_philo(t_data *data, int i)
{
	data->philo[i].left_fork = &data->fork[i];
	data->philo[i].right_fork = &data->fork[(i + 1) % data->nb_philo];
}

void	init_data(char **av, t_data *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		data->nb_must_eat = ft_atoi(av[5]);
	data->has_eaten = 0;
	data->is_dead = 0;
	if (av[5])
		data->nb_must_eat = ft_atoi(av[5]);
	else
		data->nb_must_eat = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	return ;
}

void	init_fork(t_data *data)
{
	int		i;

	i = 0;
	pthread_mutex_init(&data->message, NULL);
	pthread_mutex_init(&data->is_dead_m, NULL);
	pthread_mutex_init(&data->mutex, NULL);
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
}

void	init_philo(t_data *data)
{
	int		i;

	i = 0;
	data->time_start = get_time();
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return ;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->philo[i].last_eat = 0;
		data->philo[i].meals = 0;
		assign_forks_to_philo(data, i);
		if (pthread_create(&data->philo[i].thread, NULL, &routine,
				&data->philo[i]))
			return ;
		i++;
	}
	monitoring(data);
}
