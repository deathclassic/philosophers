/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:24:29 by tcharmel          #+#    #+#             */
/*   Updated: 2022/01/17 16:36:48 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	invite_even_phil(t_config *config)
// {
// 	int			i;
// 	pthread_t	thread;
	
// 	while(i < config->n_phil)
// 	{
// 		if (i % 2 == 0)
// 		{
// 			config->phil[i].last_dinner = config->start;
// 			if (pthread_create(&thread, NULL, philo_cycle, &config->phil[i]))
// 			{
// 				pthread_mutex_lock(config->start);
// 				return (1);
// 			}
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	invite_odd_phil(t_config *config)
// {
// 	int			i;
// 	pthread_t	thread;
	
// 	while(i < config->n_phil)
// 	{
// 		if (i % 2 == 1)
// 		{
// 			config->phil[i].last_dinner = config->start;
// 			if (pthread_create(&thread, NULL, philo_cycle, &config->phil[i]))
// 			{
// 				pthread_mutex_lock(config->start);
// 				return (1);
// 			}
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	philosophers(t_config *config)
// {
// 	pthread_t	thread;

// 	config->p_full = 0;
// 	config->start = get_time();
// 	if (invite_even_phill(config));
// 		return (1);
// 	usleep(10000);
// 	if (invite_odd_phil(config));
// 		return (1);
// 	if (pthread_create(&thread, NULL, monitoring, config))
// 	{
// 		pthread_mutex_lock(config->speech);
// 		return (1);
// 	}
// 	pthread_join(thread, NULL);
// 	return (0);
// }

int main(int argc, char **argv)
{
	t_config	config;

	if (argc != 5 && argc != 6)
		return (error_message(1));
	config.n_phil = ft_atoi(argv[1]);
	config.die_time = ft_atoi(argv[2]);
	config.eat_time = ft_atoi(argv[3]);
	config.sleep_time = ft_atoi(argv[4]);
	printf("data: %d %d %d %d\n", config.n_phil, config.die_time, config.eat_time, config.sleep_time);
	config.eat_limit = 0;
	if (argc == 6)
	{
		config.eat_limit = ft_atoi(argv[5]);
		if (config.eat_limit < 1)
			return (error_message(1));
	}
	if (config.n_phil < 1 || config.die_time < 1 || config.eat_time < 1 ||\
		config.sleep_time < 1)
		return (error_message(1));
	initialize(&config);
	printf("everything is initialized\n");
	exit (1);
	// if (philosophers(&config))
	// 	return (error_message(2));
	return(0);
}
