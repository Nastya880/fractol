/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:42:38 by tandroma          #+#    #+#             */
/*   Updated: 2022/01/27 14:10:02 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static int	ft_symbol(const char *str, int i)
{
	if (str[i] == '-')
		return (-1);
	return (1);
}

static double	ft_part_number(const char *str)
{
	int	num;

	num = 0;
	while (str || *str != '.')
	{
		if (*str >= 48 && *str <= 57)
			num = num * 10 + (*str - 48);
		else
			return (num);
		str++;
	}
	return (num);
}

double	ft_atoi_double(const char *str)
{
	int			i;
	int			neg;
	double		num_int;
	double		num_dec;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	neg = ft_symbol(str, i);
	if (str[i] == '-' || str[i] == '+')
		i++;
	num_int = ft_part_number(str);
	num_dec = ft_part_number(str);
	return ((num_int + num_dec) * neg);
}
