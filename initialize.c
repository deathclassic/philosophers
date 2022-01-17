/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:54:18 by tcharmel          #+#    #+#             */
/*   Updated: 2022/01/17 16:20:58 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philos(t_config *config)
{
	int	i;

	i = 0;
	config->phil = (t_phil *)malloc(sizeof(t_phil) * config->n_phil);
	while(i < config->n_phil)
	{
		config->phil[i].id = i;
		config->phil[i].data = config;
		config->phil[i].had_dinner = 0;
		config->phil[i].is_full = &(config->p_full);
		i++;
	}
}

void	init_mtx(t_config *config)
{
	int	i;

	i = 0;
	config->all_forks = (t_mtx *)malloc(sizeof(t_mtx) * config->n_phil);
	while (i < config->n_phil)
	{
		pthread_mutex_init(&(config->all_forks[i]), NULL);
		i++;
	}
	config->speech = (t_mtx *)malloc(sizeof(t_mtx));
	pthread_mutex_init(config->speech, NULL);
}

void	initialize(t_config *config)
{
	int	i;
	int	j;

	i = 0;
	init_philos(config);
	init_mtx(config);
	while(i < config->n_phil)
	{
		j = (i + 1) % config->n_phil;
		config->phil[i].speech = config->speech;
		config->phil[i].left_f = &(config->all_forks[i]);
		config->phil[i].right_f = &(config->all_forks[j]);
		i++;
	}
}