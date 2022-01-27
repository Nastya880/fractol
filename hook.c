/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:04:40 by tandroma          #+#    #+#             */
/*   Updated: 2022/01/27 14:10:11 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static void	key_cursor(int keycode, t_fractol *fractol)
{
	if (keycode == UP)
		fractol->mouse.im += 20;
	if (keycode == DOWN)
		fractol->mouse.im -= 20;
	if (keycode == LEFT)
		fractol->mouse.re -= 20;
	if (keycode == RIGHT)
		fractol->mouse.re += 20;
	if (keycode == ZOOM_IN)
		fractol->zoom *= 1.1;
	if (keycode == ZOOM_OUT)
		fractol->zoom /= 1.1;
}

static void	key_iteration(int keycode, t_fractol *fractol)
{
	if (keycode == MORE_ITER)
		fractol->max_iteration += 1;
	if (keycode == LESS_ITER)
		fractol->max_iteration -= 1;
}

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		exit (0);
	}
	if (keycode == CHANGE_COLOR)
	{
		fractol->color.red += 4;
		fractol->color.blue += 4;
		fractol->color.green += 4;
		fractol_print_for_change_color(fractol);
		return (0);
	}
	key_cursor(keycode, fractol);
	key_iteration(keycode, fractol);
	fractol_print(fractol);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	x -= WIN_WIDTH / 2;
	y -= WIN_HEIGHT / 2;
	if (button == SCROLL_UP)
	{
		fractol->zoom *= 1.1;
		fractol->max_iteration += 1;
		fractol->mouse.re += x / fractol->zoom / 2.5;
		fractol->mouse.im -= y / fractol->zoom / 2.5;
	}
	if (button == SCROLL_DOWN)
	{
		if (fractol->zoom > 0.11)
			fractol->zoom /= 1.1;
		if (fractol->max_iteration > 10)
			fractol->max_iteration -= 1;
	}
	fractol_print(fractol);
	return (0);
}

int	red_cross(void)
{
	exit(0);
}
