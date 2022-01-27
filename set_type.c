/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:54:40 by tandroma          #+#    #+#             */
/*   Updated: 2022/01/27 14:10:26 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static int	check_parametr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else if (str[i] == '.' || str[i] == '-' || str[i] == '+')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_two_parametrs(char *str1, char *str2)
{
	if (check_parametr(str1) && check_parametr(str2))
		return (1);
	return (0);
}

void	choose_type_fractol(int argc, char **argv_type, t_fractol *fractol)
{
	if (argc == 4 && check_two_parametrs(argv_type[2], argv_type[3]))
	{
		if (!(ft_strncmp(argv_type[1], "Julia", 5)))
		{	
			fractol->type = 2;
			fractol->julia_c.re = ft_atoi_double(argv_type[2]);
			fractol->julia_c.im = ft_atoi_double(argv_type[3]);
		}
	}
	else if (argc == 2 && !(ft_strncmp(argv_type[1], "Julia", 5)))
	{
		fractol->julia_c.re = 0.36;
		fractol->julia_c.im = 0.36;
		fractol->type = 2;
	}
	else if (!(ft_strncmp(argv_type[1], "Mandelbrot", 10)))
		fractol->type = 1;
	else if (!(ft_strncmp(argv_type[1], "Newton pool", 10)))
		fractol->type = 3;
	else
		fractol->type = 0;
}
