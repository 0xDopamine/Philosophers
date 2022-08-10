/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:38:04 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/09 22:44:43 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char **argv)
{
	t_philo *philo;
	t_data	*data;
	int		i;
	int		j;

	philo = malloc(sizeof(t_philo));
	data = malloc(sizeof(t_data));
	i = 0;
	j = -1;
	if (argc == 5 || argc == 6)
	{
		data->argc = argc;
		philo->ph_data = malloc(sizeof(int) * argc);
		while (argv[++i])
		{
			if (ft_check_argument(argv[i]))
				philo->ph_data[++j] = ft_atoi(argv[i]);
			else
				perror("Arguments should be valid numeric values.");
		}
		ft_philosophers(philo);
	}
	else
		perror("Only 4 or 5 arguments allowed.");
	return (0);
}