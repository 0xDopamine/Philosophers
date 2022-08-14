/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:53:35 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/14 05:39:34 by mbaioumy         ###   ########.fr       */
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
		if (time >= (long)(ph->data.time_death))
		{
            pthread_mutex_lock(&ph->data.message);
			print_msg(ph->philo->id, current_time, DIE);
            pthread_mutex_unlock(&ph->data.message);
			return (DEAD);
		}
		i++;	
	}
	return (ALIVE);
}

void    *ft_supervisor(void *arg)
{
    long int	time;
    t_ph 		*ph;

    ph = (t_ph *)arg;
    time = actual_time();
	ft_usleep(ph->data.time_death + 1);
    ph->data.index = 0;
	pthread_mutex_lock(&ph->sup_mutex);
    if (check_death(time, ph) == DEAD)
        exit(1);
	pthread_mutex_unlock(&ph->sup_mutex);
    return (0);
}