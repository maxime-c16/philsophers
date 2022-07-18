/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:47:20 by mcauchy           #+#    #+#             */
/*   Updated: 2022/06/16 09:35:06 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*check_meals(t_data *data, int i)
{
	pthread_mutex_lock(&data->philo[i].data->mutex);
	if (data->philo[i].meals >= data->nb_must_eat
		&& data->nb_must_eat > 0)
	{
		data->has_eaten++;
		if (data->has_eaten == data->nb_philo)
		{
			data->is_dead = 1;
			pthread_mutex_unlock(&data->philo[i].data->mutex);
			return (NULL);
		}
	}
	pthread_mutex_unlock(&data->philo[i].data->mutex);
	return (&data->philo[i]);
}

void	*monitoring(t_data *data)
{
	int		i;

	while (1)
	{
		i = -1;
		data->has_eaten = 0;
		while (++i < data->nb_philo)
		{
			if (check_meals(data, i) == NULL)
				return (NULL);
			if (kill_philo(data->philo + i))
				return (NULL);
			usleep(400);
		}
	}
}
