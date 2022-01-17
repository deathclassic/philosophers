/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:47:10 by tcharmel          #+#    #+#             */
/*   Updated: 2022/01/17 18:01:00 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	death(t_config *config, int i)
{
	pthread_mutex_lock(config->speech);
	if (get_time() - config->phil[i].last_dinner > config->die_time)
	{
		printf("time %lld: %d is dead... F\n", get_time() - config->start, i + 1);
		return (1);
	}
	pthread_mutex_unlock(config->speech);
	return (0);
}

void	free_all(t_config *config)
{
	free(config->speech);
	free(config->all_forks);
	free(config->phil);
}