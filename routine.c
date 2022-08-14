/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 05:18:56 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/14 05:43:35 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_forks(t_ph *ph, int id, int id_2)
{
	if (pthread_mutex_lock(&ph->philo[id].fork) != 0)
			perror("Failed to lock fork 1");
		print_msg(id, actual_time(), FORK);
		if (pthread_mutex_lock(&ph->philo[id_2].fork) != 0)
			perror("Failed to lock fork 2");
        pthread_mutex_lock(&ph->data.message);
		print_msg(id, actual_time(), FORK);
        pthread_mutex_unlock(&ph->data.message);
}

void	ft_eat(t_ph *ph, int id)
{
	pthread_mutex_lock(&ph->data.message);
	print_msg(id, actual_time(), EAT);
    pthread_mutex_unlock(&ph->data.message);
	pthread_mutex_lock(&ph->data.message);
    ft_usleep(ph->data.time_eat);
    pthread_mutex_unlock(&ph->data.message);
}

void	ft_sleep(t_ph *ph, int id)
{
	pthread_mutex_lock(&ph->data.message);
	print_msg(id, actual_time(), SLEEP);
    pthread_mutex_unlock(&ph->data.message);
}

void	ft_unlock_forks(t_ph *ph, int id, int id_2)
{
	pthread_mutex_unlock(&ph->philo[id].fork);
	pthread_mutex_unlock(&ph->philo[id_2].fork);
}

void	ft_think(t_ph *ph, int id)
{
	pthread_mutex_lock(&ph->data.message);
	print_msg(id, actual_time(), THINK);
	pthread_mutex_unlock(&ph->data.message);
}