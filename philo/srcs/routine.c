/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:44:44 by mcauchy           #+#    #+#             */
/*   Updated: 2022/08/12 08:55:10 by nfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	take_fork(t_philo *philo)
{
	pthread_mutex_lock((pthread_mutex_t *)((!(philo->id % 2) * (long long int)philo->right_fork) + ((philo->id %2 != 0) * (long long int)philo->left_fork)));
	mutex_message("has taken a fork", philo);
	if (is_dead(philo))
	{
		pthread_mutex_unlock((pthread_mutex_t *)((!(philo->id % 2) * (long long int)philo->right_fork) + ((philo->id %2 != 0) * (long long int)philo->left_fork)));
		return ;
	}
	pthread_mutex_lock((pthread_mutex_t *)(((philo->id % 2 != 0) * (long long int)philo->right_fork) + (!(philo->id %2) * (long long int)philo->left_fork)));
	mutex_message("has taken a fork", philo);
	philo_eat(philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (is_dead(ph) == 0)
	{
		take_fork(ph);
		if (is_dead(ph) == 1)
			return (NULL);
		philo_sleep(ph);
		if (is_dead(ph) == 1)
			return (NULL);
		philo_think(ph);
		usleep(200);
	}
	return (NULL);
}
