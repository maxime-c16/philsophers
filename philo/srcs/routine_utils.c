/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:15:54 by mcauchy           #+#    #+#             */
/*   Updated: 2022/06/16 09:39:46 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	kill_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->message);
	if (get_time_since_start(philo) - philo->last_eat
		> philo->data->time_to_die)
	{
		philo_die(philo);
		pthread_mutex_unlock(&philo->data->message);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->message);
	return (0);
}

void	philo_eat(t_philo *philo)
{
	int		time;

	time = get_time_since_start(philo);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(&philo->data->message);
		return ;
	}
	printf("%dms\t : Philosopher %d is eating\n", time, philo->id);
	pthread_mutex_lock(&philo->data->mutex);
	philo->last_eat = get_time() - philo->data->time_start;
	philo->meals++;
	pthread_mutex_unlock(&philo->data->mutex);
	ft_usleep(philo->data->time_to_eat);
}

void	philo_think(t_philo *philo)
{
	mutex_message("is thinking", philo);
}

void	philo_sleep(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	mutex_message("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	philo_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->is_dead_m);
	printf("%dms\t : Philosopher %d %s\n",
		get_time() - philo->data->time_start, philo->id, "is dead");
	philo->data->is_dead = 1;
	pthread_mutex_unlock(&philo->data->is_dead_m);
}
