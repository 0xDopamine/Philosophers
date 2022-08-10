/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:49:48 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/09 22:48:17 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

enum {
	NUM_PH,
	T_DIE,
	T_EAT,
	T_SLEEP,
	T_PH_EAT
} ;

typedef struct s_philo {
	pthread_t		ph_id;
	int				*ph_data;
	pthread_mutex_t	*fork;
	pthread_mutex_t	eat;
	pthread_mutex_t	sleep;
} t_philo ;

typedef struct s_data {
	int	argc;
	
} t_data ;

int			ft_isdigit(int c);
int			ft_check_argument(char *arg);
int			ft_atoi(const char *str);
void		ft_philosophers(t_philo *philo);
#endif