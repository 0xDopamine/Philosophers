/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:33:52 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/10 02:23:46 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	pthread_mutex_lock(ph->fork);
	printf("has taken a fork..\n");
	usleep(3);
	pthread_mutex_unlock(ph->fork);
	return (0);
}

void	ft_philosophers(t_philo *philo)
{
	int	i;

	i = 0;
	philo->ph_id = malloc(sizeof(pthread_t) * philo->ph_data[NUM_PH]);
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->ph_data[NUM_PH]);
	while (i < philo->ph_data[NUM_PH])
	{
		if (pthread_mutex_init(&philo->eat, NULL) != 0)
			perror("Mutex init error.");
		if (pthread_create(&philo->ph_id, NULL, routine, &philo) != 0)
			perror("Thread creation error.");
		i++;
	}
}