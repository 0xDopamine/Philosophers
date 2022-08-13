/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:53:35 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/13 08:40:20 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_death(long int current_time, t_ph *ph)
{
	long int	time;
	int			i;

	i = 0;
	while (i < ph->data.total)
	{
		time = current_time - ph->philo[i].last_meal;
		if (time > ph->data.time_death)
		{
            pthread_mutex_lock(&ph->sup_mutex);
			print_msg(ph->philo->id, current_time, DIE);
            pthread_mutex_unlock(&ph->sup_mutex);
			return (DEAD);
		}
		i++;	
	}
	return (ALIVE);
}

void    *ft_supervisor(void *arg)
{
    long int    time;
    t_ph *ph;

    ph = (t_ph *)arg;
    time = actual_time();
    ph->data.index = 0;
	ft_usleep(ph->data.time_death + 1);
    if (check_death(time, ph) == DEAD)
        exit(1);
    return (0);
}