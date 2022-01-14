/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:24:29 by tcharmel          #+#    #+#             */
/*   Updated: 2022/01/14 15:27:59 by tcharmel         ###   ########.fr       */
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
	if (i == 2)
	{
		printf("Failure: philosopher has died. F\n");
	}
	return (0);
}

int	philosophers(t_config *config)
{
	t_mutex	*fork;

	fork = (t_mutex *)malloc(sizeof(t_mutex) * config->n_phil);
}

int main(int argc, char **argv)
{
	t_config	config;

	if (argc != 5 && argc != 6)
		return (error_message(1));
	config.n_phil = ft_atoi(argv[1]);
	config.die = ft_atoi(argv[2]);
	config.eat = ft_atoi(argv[3]);
	config.sleep = ft_atoi(argv[4]);
	config.n_eat = 0;
	if (argc == 6)
	{
		config.n_eat = ft_atoi(argv[5]);
		if (config.n_eat <= 0)
			return (error_message(1));
	}
	if (config.n_phil < 1 || config.die < 0 || config.eat < 0 ||\
		config.sleep < 0 || config.n_eat < 0)
		return (error_message(1));
	if (philosophers(&config))
		return (error_message(2));
	return(0);
}
