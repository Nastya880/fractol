/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:30:20 by tandroma          #+#    #+#             */
/*   Updated: 2022/01/27 14:09:57 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static void	fractol_init(t_fractol *fractol)
{
	fractol->start.re = 0;
	fractol->start.im = 0;
	fractol->mouse.re = 0;
	fractol->mouse.im = 0;
	fractol->zoom = 0.5;
	fractol->max_iteration = 18;
	fractol->color.red = 26;
	fractol->color.green = 18;
	fractol->color.blue = 247;
}

void	create_window(t_fractol *fr)
{
	fractol_init(fr);
	fr->mlx = mlx_init();
	fr->win = mlx_new_window(fr->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	fractol_print(fr);
	mlx_hook(fr->win, 2, 1L << 3, key_hook, fr);
	mlx_hook(fr->win, 4, 1L << 3, mouse_hook, fr);
	mlx_hook(fr->win, 17, 0L, red_cross, 0);
	mlx_loop(fr->mlx);
}
