/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 05:18:56 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/14 12:00:48 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_forks(t_ph *ph, int id, int id_2)
{
	if (pthread_mutex_lock(&ph->philo[id].fork) != 0)
		write(2, "Failed to lock fork 1\n", 23);
	pthread_mutex_lock(&ph->data.message);
	print_msg(id, (actual_time() - ph->data.start_time), FORK);
	pthread_mutex_unlock(&ph->data.message);
	if (pthread_mutex_lock(&ph->philo[id_2].fork) != 0)
		write(2, "Failed to lock fork 2\n", 23);
	pthread_mutex_lock(&ph->data.message);
	print_msg(id, (actual_time() - ph->data.start_time), FORK);
	pthread_mutex_unlock(&ph->data.message);

}

void	ft_eat(t_ph *ph, int id)
{
	pthread_mutex_lock(&ph->data.message);
	print_msg(id, (actual_time() - ph->data.start_time), EAT);
    pthread_mutex_unlock(&ph->data.message);
    ft_usleep(ph->data.time_eat);
}

void	ft_sleep(t_ph *ph, int id)
{
	pthread_mutex_lock(&ph->data.message);
	print_msg(id, (actual_time() - ph->data.start_time), SLEEP);
    pthread_mutex_unlock(&ph->data.message);
	ft_usleep(ph->data.time_sleep);
}

void	ft_unlock_forks(t_ph *ph, int id, int id_2)
{
	pthread_mutex_unlock(&ph->philo[id].fork);
	pthread_mutex_unlock(&ph->philo[id_2].fork);
}

void	ft_think(t_ph *ph, int id)
{
	pthread_mutex_lock(&ph->data.message);
	print_msg(id, (actual_time() - ph->data.start_time), THINK);
	pthread_mutex_unlock(&ph->data.message);
}