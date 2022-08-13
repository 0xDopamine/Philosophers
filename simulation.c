/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:33:52 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/13 09:02:37 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*routine(void *arg)
{
	t_ph	*ph;
	int		id;
	int		id_2;

	ph = (t_ph *)arg;
	while (1)
	{
		id = ph->philo->id;
		id_2 = (id + 1) % ph->data.total;
		if (id % 2 == 0)
			ft_usleep(ph->data.time_eat / 10);
		if (pthread_mutex_lock(&ph->philo[id].fork) != 0)
			perror("Failed to lock fork 1");
		print_msg(id, actual_time(), FORK);
		if (pthread_mutex_lock(&ph->philo[id_2].fork) != 0)
			perror("Failed to lock fork 2");
		print_msg(id, actual_time(), FORK);
		// if (pthread_mutex_lock(&ph->philo[id].l_meal_mutex) != 0)
		// 	perror("Failed to lock last meal");
		ph->philo[id].last_meal = actual_time();
		// pthread_mutex_unlock(&ph->philo[id].l_meal_mutex);
		print_msg(id, actual_time(), EAT);
		ft_usleep(ph->data.time_eat);
		print_msg(id, actual_time(), SLEEP);
		pthread_mutex_unlock(&ph->philo[id].fork);
		pthread_mutex_unlock(&ph->philo[id_2].fork);
		ft_usleep(ph->data.time_sleep);
		print_msg(id, actual_time(), THINK);
	}
	return (0);
}

void	create_threads(t_ph *ph)
{
	ph->data.index = 0;
	while (ph->data.index < ph->data.total)
	{
		ph->philo[ph->data.index].id = ph->data.index;
		ph->philo->id = ph->data.index;
		if (pthread_create(&ph->philo[ph->data.index].ph_id, NULL, routine, ph))
			perror("Thread creatiog failed.");
		ph->data.index++;
	}
}

void	join_threads(t_ph *ph)
{
	ph->data.index = 0;
	while (ph->data.index < ph->data.total)
	{
		if (pthread_join(ph->philo[ph->data.index].ph_id, NULL))
			perror("Thread detach failed.");
		ph->data.index++;
	}
}

void	init_mutex(t_ph *ph)
{
	int	id_2;

	ph->data.index = 0;
	while (ph->data.index < ph->data.total)
	{
		ph->philo[ph->data.index].id = ph->data.index;
		id_2 = (ph->data.index + 1) % ph->data.total;
		if (pthread_mutex_init(&ph->philo[ph->data.index].fork, NULL) != 0)
			perror("Mutex init failed.");
		ph->data.index++;
	}
}

void	ft_philosophers()
{
	t_ph	*ph;

	ph->philo = malloc(sizeof(t_philo) * ph->data.total);
	init_mutex(ph);
	create_threads(ph);
	if (pthread_join(ph->sup_id, NULL))
		perror("Thread detach failed.");	
	join_threads(ph);
}