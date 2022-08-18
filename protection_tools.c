/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:22:25 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/15 06:46:08 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long	calres_tester(const char *str, int i, int sign)
{
	long		temp;
	long		res;

	temp = 0;
	res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		temp = (temp * 10) + (str[i] - '0');
		if (temp < res && sign == -1)
			return (0);
		if (temp < res && sign == 1)
			return (-1);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_atoi_tester(const char *str)
{
	int		i;
	long	res;
	int		sign;
	long	temp;

	sign = 1;
	res = 0;
	i = 0;
	temp = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = calres_tester(str, i, sign);
	if (res > 2147483647 || res < -2147483648)
		return (0);
	return (1);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '0')
		return (0);
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_argument(char **arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]))
		{
			if (!ft_atoi_tester(arg[i]))
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}
