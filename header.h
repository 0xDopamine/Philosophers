/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:49:48 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/09 20:26:46 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct s_philo {
	pthread_t	ph_id;
	int			*ph_data;
	
} t_philo ;

int			ft_isdigit(int c);
int			ft_check_argument(char *arg);
int			ft_atoi(const char *str);

#endif