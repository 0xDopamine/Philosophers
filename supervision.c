/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:53:35 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/18 20:06:31 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_exit(void)
{
	return ;
}

int	check_death(t_ph *ph)
{
	long int	time;
	int			i;
	long int	print_time;

	i = 0;
	while (i < ph->data.total)
	{
		if (check_eating(ph))
		{
			pthread_mutex_lock(&ph->data.message);
			return (0);
		}
		time = actual_time() - ph->philo[i].last_meal;
		if (time >= (long)(ph->data.time_death))
		{
			pthread_mutex_lock(&ph->data.message);
			print_time = actual_time() - ph->data.start_time;
			print_msg(ph->philo->id, print_time, DIE);
			pthread_mutex_unlock(&ph->data.message);	
			return (DEAD);
		}
		i++; 
		if (i == ph->data.total)
			i = 0;
	}
	return (ALIVE);
}

void	ft_supervisor(t_ph *ph)
{
	long int	time;
	int			i;

	i = 0;
	time = actual_time();
	ph->data.index = 0;
	if (check_death(ph) == DEAD)
		return ;
}
