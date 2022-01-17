/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:56:54 by tcharmel          #+#    #+#             */
/*   Updated: 2022/01/17 18:16:06 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error_message(int i)
{
	if (i == 1)
	{
		printf("Error: invalid arguments\n");
		return (1);
	}
	return (0);
}

long long	get_time(void)
{
	long long		res;
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	res = time.tv_sec * (long long)1000 + time.tv_usec/1000;
	return (res);
}

void	sync_usleep(long long time)
{
	long long	start;
	long long	end;

	start = get_time();
	end = get_time() + time;
	while (start < end)
	{
		usleep(100);
		start = get_time();
	}
}

int	ft_atoi(const char *str)
{
	int			i;
	int			m;
	long long	n;

	n = 0;
	i = 0;
	m = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		m *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		n = n * 10 + (str[i] - 48);
		if (n > 2147483647 || (m < 0 && n > 2147483648))
			return (-1);
		i++;
	}
	return ((int)(m * n));
}