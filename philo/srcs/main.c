/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:36:29 by mcauchy           #+#    #+#             */
/*   Updated: 2022/08/11 17:01:26 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	one_philo(t_data *data)
{
	printf("0ms: Philosopher %d take a fork\n", 1);
	ft_usleep(data->time_to_die);
	printf("%dms: Philosopher 1 is dead\n", data->time_to_die);
	free(data->fork);
	return (0);
}

static void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	free(data->philo);
	free(data->fork);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		printf("Usage: ./philo [nb_philo] [time_to_die] [time_to_eat] ");
		printf("[time_to_sleep] {number_of_times_each_philosopher_must_eat}\n");
		return (1);
	}
	if (check_args(av) < 0)
		return (1);
	init_data(av, &data);
	if (atoi(av[1]) == 1)
		return (one_philo(&data));
	init_fork(&data);
	init_philo(&data);
	join_threads(&data);
	return (0);
}
