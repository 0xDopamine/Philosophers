/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgs_and_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:23:40 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/14 09:34:40 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	red() 
{
	printf("\033[1;31m");
}

void	blue()
{
	printf("\033[0;34m");
}

void	reset()
{
	printf("\033[0m");
}

void    purple()
{
    printf("\033[0;35m");
}

void    print_msg(int id, long int time, state x)
{
    reset();

    if (x == EAT)
    {
        red();
        printf("%ld ms %d is eating\n", time, id);
    }
    else if (x == THINK)
        printf("%ld ms %d is thinking\n", time, id);
    else if (x == SLEEP)
    {
        blue();
        printf("%ld ms %d is sleeping\n", time, id);
    }
    else if (x == FORK)
    {
        purple();
        printf("%ld ms %d has taken a fork\n", time, id);
    }
    else if (x == DIE)
        printf("%ld ms %d is dead\n", time, id);
}