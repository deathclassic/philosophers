/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:15:33 by tcharmel          #+#    #+#             */
/*   Updated: 2022/01/17 18:00:46 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	to_think(t_phil *phil)
{
	pthread_mutex_lock(phil->speech);
	printf("time %lld: %d is thinking... hmm\n", get_time() - phil->data->start, \
	phil->id + 1);
	pthread_mutex_unlock(phil->speech);
}

void	to_sleep(t_phil *phil)
{
	pthread_mutex_lock(phil->speech);
	printf("time %lld: %d is sleeping... Zzz..\n", get_time() - phil->data->start, \
	phil->id + 1);
	pthread_mutex_unlock(phil->speech);
	sync_usleep(phil->data->sleep_time);
}

void	to_eat(t_phil *phil)
{
	phil->last_dinner = get_time();
	pthread_mutex_lock(phil->speech);
	printf("time %lld: %d is eating... yummy!\n", get_time() - phil->data->start, \
	phil->id + 1);
	pthread_mutex_unlock(phil->speech);
	sync_usleep(phil->data->eat_time);
	pthread_mutex_unlock(phil->left_f);
	pthread_mutex_unlock(phil->right_f);
	phil->had_dinner++;
}

void	get_forks(t_phil *phil)
{
	pthread_mutex_lock(phil->left_f);
	pthread_mutex_lock(phil->speech);
	printf("time %lld: %d took a left fork\n", get_time() - phil->data->start, \
	phil->id + 1);
	pthread_mutex_unlock(phil->speech);
	pthread_mutex_lock(phil->right_f);
	pthread_mutex_lock(phil->speech);
	printf("time %lld: %d took a right fork\n", get_time() - phil->data->start, \
	phil->id + 1);
	pthread_mutex_unlock(phil->speech);
}

void	*philo_cycle(void *v_phil)
{
	t_phil	*phil;
	int		lim;

	phil = (t_phil *)v_phil;
	lim = phil->data->eat_limit;
	while (1)
	{
		get_forks(phil);
		to_eat(phil);
		if (lim && phil->had_dinner == lim)
			*(phil->is_full) += 1;
		to_sleep(phil);
		to_think(phil);
	}
	return (NULL);
}