/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:36:39 by tcharmel          #+#    #+#             */
/*   Updated: 2022/01/14 15:42:18 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_list *init_list(t_phil phil, int i)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->phil = phil;
	lst->phil.id += ;
	retuurn (lst);
}