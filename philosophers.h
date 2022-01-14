/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:24:32 by tcharmel          #+#    #+#             */
/*   Updated: 2022/01/14 15:39:01 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

typedef pthread_mutex_t t_mutex;

typedef struct s_config{
	int		n_phil;
	int		eat;
	int		sleep;
	int		die;
	int		n_eat;
	t_mutex	*mtx;
}	t_config;

typedef struct s_phil{
	t_config	data;
	t_mutex		*left;
	t_mutex		*right;
	int			status;
	int			id;
}	t_phil;

typedef struct s_list{
	t_phil			phil;
	struct	s_list *next;
}	t_list;

#endif