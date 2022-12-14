/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:13:59 by maximecauch       #+#    #+#             */
/*   Updated: 2022/06/06 00:14:10 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_intlen(long long int n)
{
	long long int	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_fill_str(char *str, long long int n, int len)
{
	int		start;

	str[len] = 0;
	len -= 1;
	if (n < 0)
	{
		n *= -1;
		start = 1;
		str[0] = '-';
	}
	else
		start = 0;
	while (len >= start)
	{
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	long long int	buff;

	buff = n;
	len = ft_intlen(buff);
	if (buff < 0)
		len = len + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	str = ft_fill_str(str, buff, len);
	return (str);
}
