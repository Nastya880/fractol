/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:17:34 by tandroma          #+#    #+#             */
/*   Updated: 2022/01/27 14:10:06 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc == 2 || argc == 4)
	{
		fractol = malloc(sizeof(t_fractol));
		if (fractol == NULL)
		{
			ft_putstr_fd("error in memory allocate for fractol\n", 1);
			exit(1);
		}
		choose_type_fractol(argc, argv, fractol);
		if (fractol->type == 0)
		{
			free(fractol);
			print_arg();
			return (0);
		}
		create_window(fractol);
		return (0);
	}
	else
		print_arg();
	return (0);
}
