/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:53:35 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/14 11:48:24 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_death(t_ph *ph)
{
	long int	time;
	int			i;

	i = 0;
	if (ph->data.stop)
	{
		while (i < ph->data.total)
		{
			time = actual_time() - ph->philo[i].last_meal;
			if (time >= (long)(ph->data.time_death))
			{
				pthread_mutex_lock(&ph->data.message);
				print_msg(ph->philo->id, (actual_time() - ph->data.start_time), DIE);
				return (DEAD);
			}
			i++;
			if (i == ph->data.total)
				i = 0; 	
		}
	}
	return (ALIVE);
}

void    *ft_supervisor(t_ph *ph)
{
    long int	time;

	time = actual_time();
	ph->data.index = 0;
	if (check_death(ph) == DEAD)
		exit(1);
	return (0);
}