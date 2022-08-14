/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:33:52 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/14 11:14:15 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*routine(void *arg)
{
	t_ph		*ph;
	int			id;
	int			id_2;

	ph = (t_ph *)arg;
	id = ph->philo->id;
	id_2 = (id + 1) % ph->data.total;
	ph->philo[id].last_meal = actual_time();
	while (1)
	{
		if (ph->data.must_eat != -1 && ph->philo[id].meals <= ph->data.must_eat)
		{
			ft_forks(ph, id, id_2);
			if (pthread_mutex_lock(&ph->philo[id].l_meal_mutex) != 0)
				perror("Failed to lock last meal");
			ph->philo[id].last_meal = actual_time();
			pthread_mutex_unlock(&ph->philo[id].l_meal_mutex);
			ft_eat(ph, id);
			ft_unlock_forks(ph, id, id_2);
		}
		else
			exit(1);
		ft_sleep(ph, id);
		ft_think(ph, id);
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
			perror("Thread creation failed.");
		ph->philo[ph->data.index].meals = 0;
		usleep(100);
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
	ph->data.index = 0;
	while (ph->data.index < ph->data.total)
	{
		ph->philo[ph->data.index].id = ph->data.index;
		if (pthread_mutex_init(&ph->philo[ph->data.index].fork, NULL) != 0)
			perror("Mutex init failed.");
		if (pthread_mutex_init(&ph->philo[ph->data.index].l_meal_mutex, NULL) != 0)
			perror("Mutex init failed.");
		ph->data.index++;
	}
}

void	ft_philosophers(t_ph *ph)
{
	ph->philo = malloc(sizeof(t_philo) * ph->data.total);
	pthread_mutex_init(&ph->data.message, NULL);
	init_mutex(ph);
	create_threads(ph);	
}