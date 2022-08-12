/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:53:35 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/12 11:58:27 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    ft_supervisor(t_ph *ph)
{
    
    ph->data.index = 0;
    while (ph->data.index < ph->data.total)
    {
        // if (pthread_create())
        ph->data.index++;
    }
}