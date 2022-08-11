/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:44:44 by mcauchy           #+#    #+#             */
/*   Updated: 2022/08/11 19:33:59 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static pthread_mutex_t	*lol(t_philo *philo, int i)
{
	if (!(philo->id % 2))
	{
		if (!i)
			return (philo->right_fork);
		else
			return (philo->left_fork);
	}
	else
	{
		if (!i)
			return (philo->left_fork);
		else
			return (philo->right_fork);
	}
}

static void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(lol(philo, 0));
	mutex_message("has taken a fork", philo);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(lol(philo, 0));
		return ;
	}
	pthread_mutex_lock(lol(philo, 1));
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
