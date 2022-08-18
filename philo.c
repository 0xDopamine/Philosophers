/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:38:04 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/18 13:22:41 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_ph	*ph;
	int		i;

	i = -1;
	ph = malloc(sizeof(t_ph));
	if (argc == 5 || argc == 6)
	{
		if (ft_check_argument(argv))
		{
			ph->data.total = ft_atoi(argv[1]);
			ph->data.time_death = ft_atoi(argv[2]);
			ph->data.time_eat = ft_atoi(argv[3]);
			ph->data.time_sleep = ft_atoi(argv[4]);
			ph->data.must_eat = -1;
			if (argc == 6)
				ph->data.must_eat = ft_atoi(argv[5]);
			ph->data.start_time = actual_time();
			ph->data.stop = 1;
			ft_philosophers(ph);
			ft_supervisor(ph);	
		}
		else
			write(2, "Invalid argument\n", 18);
	}
	else
		write(2, "Only 4 or 5 arguments allowed.\n", 32);
	return (0);
}
