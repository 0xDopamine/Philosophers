/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:33:52 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/18 20:05:24 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_eating(t_ph* ph)
{
	int	i;

	i = 0;
	while (i < ph->data.total)
	{
		if (ph->philo[i].meals < ph->data.must_eat)
				return (0);
		i++;
	}
	return (1);
}

void	*routine(void *arg)
{
	t_ph		*ph;
	int			id;
	int			id_2;

	ph = (t_ph *)arg;
	id = ph->philo->id;
	id_2 = (id + 1) % ph->data.total;
	ph->philo[id].last_meal = actual_time();
	while (ph->data.stop)
	{
		ft_forks(ph, id, id_2);
		if (pthread_mutex_lock(&ph->philo[id].l_m_mutex) != 0)
			write(2, "Failed to lock last meal\n", 26);
		ph->philo[id].last_meal = actual_time();
		pthread_mutex_unlock(&ph->philo[id].l_m_mutex);
		ft_eat(ph, id);
		if (ph->data.must_eat != -1 && ph->philo[id].meals <= ph->data.must_eat)
			ph->philo[id].meals++;
		ft_unlock_forks(ph, id, id_2);
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
		ph->philo->id = ph->data.index;
		ph->philo[ph->data.index].meals = 0;
		if (pthread_create(&ph->philo[ph->data.index].ph_id, NULL, routine, ph))
			write(2, "Thread creation failed.\n", 25);
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
			write(2, "Thread detach failed.\n", 23);
		ph->data.index++;
	}
}

void	init_mutex(t_ph *ph)
{
	ph->data.index = 0;
	while (ph->data.index < ph->data.total)
	{
		if (pthread_mutex_init(&ph->philo[ph->data.index].fork, NULL) != 0)
			write(2, "Mutex init failed.\n", 20);
		if (pthread_mutex_init(&ph->philo[ph->data.index].l_m_mutex, NULL) != 0)
			write(2, "Mutex init failed.", 20);
		if (pthread_mutex_init(&ph->data.sup_id, NULL) != 0)
			write(2, "Mutex init failed.\n", 20);
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
