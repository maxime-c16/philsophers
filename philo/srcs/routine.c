/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:44:44 by mcauchy           #+#    #+#             */
/*   Updated: 2022/07/18 17:02:52 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0 && !is_dead(philo))
	{
		pthread_mutex_lock(philo->right_fork);
		mutex_message("has taken a fork", philo);
		if (is_dead(philo) == 1)
			return (1);
		pthread_mutex_lock(philo->left_fork);
		mutex_message("has taken a fork", philo);
		philo_eat(philo);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		mutex_message("has taken a fork", philo);
		if (is_dead(philo) == 1)
			return (1);
		pthread_mutex_lock(philo->right_fork);
		mutex_message("has taken a fork", philo);
		philo_eat(philo);
	}
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
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
