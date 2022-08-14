/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:06:34 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/14 11:13:05 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    ft_exit(t_ph *ph)
{
	int	i;

	i = -1;
	while (++i < ph->data.total)
		pthread_detach(ph->philo[i].ph_id);
	return ;
}