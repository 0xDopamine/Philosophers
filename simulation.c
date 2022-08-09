/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:33:52 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/09 20:39:41 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	routine()
{
	
}

void	ft_philosophers(t_philo *philo)
{
	int	i;

	i = 0;
	philo->ph_id = philo->ph_data[0];
	while (i < 5)
	{
		if (pthread_create(&philo->ph_id, NULL, routine, NULL) != 0)
			perror("Thread creation error.");
		i++;
	}
}