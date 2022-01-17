/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:24:32 by tcharmel          #+#    #+#             */
/*   Updated: 2022/01/17 17:58:45 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

typedef pthread_mutex_t t_mtx;
typedef struct s_config t_config;

typedef struct s_phil{
	long long	last_dinner;
	t_config	*data;
	t_mtx		*left_f;
	t_mtx		*right_f;
	t_mtx		*speech;
	int			id;
	int			time_left;
	int			had_dinner;
	int			is_eating;
	int			*is_full;
}	t_phil;

typedef struct s_config{
	int			n_phil;
	int			eat_time;
	int			sleep_time;
	int			die_time;
	int			eat_limit;
	int			p_full;
	t_mtx		*all_forks;
	t_mtx		*speech;
	t_phil		*phil;
	long long	start;
}	t_config;

int			ft_atoi(const char *str);
long long	get_time(void);
int			error_message(int i);
void		initialize(t_config *config);
void		*philo_cycle(void *v_phil);
void		sync_usleep(long long time);
int			death(t_config *config, int i);
void		free_all(t_config *config);

#endif