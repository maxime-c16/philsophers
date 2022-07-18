/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:21:14 by mcauchy           #+#    #+#             */
/*   Updated: 2022/06/12 18:50:36 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				printf("Usage: ./philo [nb_philo] [time_to_die]");
				printf(" [time_to_eat][time_to_sleep] ");
				printf("{number_of_times_each_philosopher_must_eat}\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_time(char **av)
{
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
	{
		printf("Usage: ./philo [nb_philo] [time_to_die] [time_to_eat] ");
		printf("[time_to_sleep] {number_of_times_each_philosopher_must_eat}\n");
		return (-1);
	}
	return (0);
}

static int	check_nb_philo(char **av)
{
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
	{
		printf("Usage: ./philo [nb_philo] [time_to_die] [time_to_eat] ");
		printf("[time_to_sleep] {number_of_times_each_philosopher_must_eat}\n");
		return (-1);
	}
	return (0);
}

int	check_args(char **av)
{
	if (check_digit(av) < 0)
		return (-1);
	if (check_time(av) < 0)
		return (-1);
	if (check_nb_philo(av) < 0)
		return (-1);
	return (0);
}
