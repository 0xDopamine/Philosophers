/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:38:04 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/09 20:33:38 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char **argv)
{
	t_philo *philo;
	int		i;
	int		j;

	philo = malloc(sizeof(t_philo));
	i = 1;
	j = 0;	
	if (argc == 5 || argc == 6)
	{
		philo->ph_data = malloc(sizeof(int) * argc);
		while (argv[i])
		{
			if (ft_check_argument(argv[i]))
				philo->ph_data[j] = ft_atoi(argv[i]);
			else
				perror("Arguments should be valid numeric values.");
			i++;
			j++;
		}
	}
	else
		perror("Only 4 or 5 arguments allowed.");
	ft_philosophers(philo);
	return (0);
}