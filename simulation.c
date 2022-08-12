/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:33:52 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/12 11:50:34 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_death(long int current_time, t_ph *ph)
{
	long int	time;

	time = current_time - ph->philo->last_meal;
	if (time > ph->data.time_death)
		return (DEAD);
	return (ALIVE);
}

void	*routine(void *arg)
{
	t_ph	*ph;
	int		id;
	int		id_2;

	ph = (t_ph *)arg;
	// ft_usleep(1000);
	while (1)
	{
		id = ph->philo->id;
		id_2 = (id + 1) % ph->data.total;
		// if (ph->philo->id % 2 == 0)
		// 	ft_usleep(ph->data.time_eat / 10);
		// if (ph->philo->id == ph->data.total - 1)
		// {
		// 	if (pthread_mutex_lock(&ph->philo[id].fork_l) != 0)
		// 		perror("Failed to lock mutex");
		// 	if (pthread_mutex_lock(ph->philo[0].fork_r) != 0)
		// 		perror("Failed to lock mutex");	
		// }
		// else
		// {	
			if (pthread_mutex_lock(&ph->philo[id].fork_l) != 0)
				perror("Failed to lock mutex 1");
			if (pthread_mutex_lock(ph->philo[id_2].fork_r) != 0)
				perror("Failed to lock mutex 2");
		// }
		print_msg(id, actual_time(), FORK);
		print_msg(id, actual_time(), EAT);
		ft_usleep(ph->data.time_eat);
		ph->philo->last_meal = actual_time();
		if (check_death(actual_time(), ph) == DEAD)
		{
			print_msg(id, actual_time(), DEAD);
			exit(1);
		}
		print_msg(id, actual_time(), SLEEP);
		ft_usleep(ph->data.time_sleep);
		// if (ph->philo->id == ph->data.total - 1)
		// {
		// 	pthread_mutex_unlock(&ph->philo[id].fork_l);
		// 	pthread_mutex_unlock(ph->philo[0].fork_r);
		// }
		// else
		// {
			pthread_mutex_unlock(&ph->philo[id].fork_l);
			pthread_mutex_unlock(ph->philo[id_2].fork_r);
		// }
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
	ph->data.index = 0;
	while (ph->data.index < ph->data.total)
	{
		ph->philo[ph->data.index].id = ph->data.index;
		if (pthread_mutex_init(&ph->philo[ph->data.index].fork_l, NULL) != 0)
			perror("Mutex init failed.");
		if (ph->data.index == ph->data.total - 1)
			ph->philo[ph->data.index].fork_r = &ph->philo[0].fork_l;
		else
			ph->philo[ph->data.index].fork_r = &ph->philo[ph->data.index + 1].fork_l;
		ph->data.index++;
	}
}

void	ft_philosophers(t_ph *ph)
{
	ph->philo = malloc(sizeof(t_philo) * ph->data.total);
	init_mutex(ph);
	create_threads(ph);
	join_threads(ph);
}