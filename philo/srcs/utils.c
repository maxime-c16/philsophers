/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:26:15 by mcauchy           #+#    #+#             */
/*   Updated: 2022/06/16 09:48:31 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_usleep(int time)
{
	int	hit;

	hit = get_time() + time;
	while (get_time() < hit)
		usleep(10);
}

void	mutex_message(char *msg, t_philo *philo)
{
	int	time;

	time = get_time();
	pthread_mutex_lock(&philo->data->message);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(&philo->data->message);
		return ;
	}
	printf("%dms\t : Philosopher %d %s\n",
		time - philo->data->time_start, philo->id, msg);
	pthread_mutex_unlock(&philo->data->message);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->is_dead_m);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->is_dead_m);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->is_dead_m);
	return (0);
}
