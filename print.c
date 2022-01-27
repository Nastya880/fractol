/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:30:48 by tandroma          #+#    #+#             */
/*   Updated: 2022/01/27 14:10:16 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	print_arg(void)
{
	ft_putstr_fd("Please, choose and write:\n", 1);
	ft_putstr_fd("--> Mandelbrot\n", 1);
	ft_putstr_fd("--> Julia\n", 1);
	ft_putstr_fd("--> Newton pool\n", 1);
}

void	fractol_print(t_fractol *fr)
{
	fr->image.image = mlx_new_image(fr->mlx, WIN_WIDTH, WIN_HEIGHT);
	fractol_color_definition(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->image.image, 0, 0);
	mlx_destroy_image(fr->mlx, fr->image.image);
}

void	fractol_print_for_change_color(t_fractol *fr)
{
	fr->image.image = mlx_new_image(fr->mlx, WIN_WIDTH, WIN_HEIGHT);
	fractol_color_definition_for_change(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->image.image, 0, 0);
	mlx_destroy_image(fr->mlx, fr->image.image);
}
