/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:33:52 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/11 07:36:48 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*routine(void *arg)
{
	t_ph	*ph;
	int		id;

	ph = (t_ph *)arg;
	id = ph->data.index;
	if (pthread_mutex_lock(&ph->philo[0].fork_r[0]) != 0)
		perror("Failed to lock mutex 1");
	if (pthread_mutex_lock(&ph->philo[0].fork_l) != 0)
		perror("Failed to lock mutex 2");
	printf("%d has taken a fork..\n", id);
	// usleep(3);
	pthread_mutex_unlock(&ph->philo[0].fork_r[0]);
	pthread_mutex_unlock(&ph->philo[0].fork_l);
	return (0);
}

void	ft_philosophers(t_ph *ph)
{
	ph->philo = malloc(sizeof(t_philo) * ph->data.total);
	ph->data.index = 0;
	while (ph->data.index < ph->data.total)
	{
		printf("mutex init\n");
		ph->philo[ph->data.index].id = ph->data.index + 1;
		if (pthread_mutex_init(&ph->philo[ph->data.index].fork_l, NULL) != 0)
			perror("Mutex init failed.");
		if (ph->data.index == ph->data.total - 1)
			ph->philo[ph->data.index].fork_r = &ph->philo[0].fork_l;
		else
			ph->philo[ph->data.index].fork_r = &ph->philo[ph->data.index + 1].fork_l;
		ph->data.index++;
	}
	ph->data.index = 0;
	while (ph->data.index < ph->data.total)
	{
		printf("create thread %d\n", ph->data.index);
		ph->philo[ph->data.index].id = ph->data.index + 1;
		if (pthread_create(&ph->philo[ph->data.index].ph_id, NULL, routine, &ph))
			perror("Thread creatiog failed.");
		ph->data.index++;
	}
}