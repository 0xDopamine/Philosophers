/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:33:52 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/14 05:44:45 by mbaioumy         ###   ########.fr       */
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
	if (id % 2 == 0)
		ft_usleep(ph->data.time_eat / 10);
	while (1)
	{
		if (pthread_create(&ph->sup_id, NULL, ft_supervisor, ph) != 0)
			perror("Supervisor thread creation failed.");
		pthread_mutex_lock(&ph->sup_mutex);
		ft_forks(ph, id, id_2);
		ft_eat(ph, id);
		if (pthread_mutex_lock(&ph->philo[id].l_meal_mutex) != 0)
		 	perror("Failed to lock last meal");
		ph->philo[id].last_meal = actual_time();
		pthread_mutex_unlock(&ph->philo[id].l_meal_mutex);
		pthread_mutex_lock(&ph->sup_mutex);
		ft_sleep(ph, id);
		ft_unlock_forks(ph, id, id_2);
        pthread_mutex_lock(&ph->data.message);
		ft_usleep(ph->data.time_sleep);
        pthread_mutex_unlock(&ph->data.message);
		ft_think(ph, id);
		pthread_join(ph->sup_id, NULL);
		pthread_mutex_unlock(&ph->sup_mutex);
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
	join_threads(ph);
}