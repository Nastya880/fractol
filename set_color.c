/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:03:40 by tandroma          #+#    #+#             */
/*   Updated: 2022/01/27 14:10:21 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static void	put_pixel(t_fractol *fractol, int x, int y, unsigned long color)
{
	t_image	pic;
	int		pos;

	pic.data = mlx_get_data_addr(fractol, &pic.bpp, &pic.sizeline, &pic.endian);
	pos = x * 4 + y * pic.sizeline;
	if (x >= 0 && y >= 0 && x <= WIN_WIDTH && y <= WIN_HEIGHT)
	{
		pic.data[pos] = color % 256;
		pic.data[pos + 1] = color % 128;
		pic.data[pos + 2] = color % 64;
	}
}

static int	get_rgb_smooth(t_fractol *fr, int a, int c_c)
{
	int	color;

	fr->color.red = (int)(9 * (1 - a) * pow(a, 3) * 255) + c_c;
	fr->color.green = (int)(15 * pow((1 - a), 2) * pow(a, 2) * 255) + c_c;
	fr->color.blue = (int)(8.5 * pow((1 - a), 3) * a * 255) + c_c;
	color = fr->color.red + fr->color.green + fr->color.blue;
	return (color);
}

static int	fractol_type(t_fractol *fractol, int x, int y)
{
	int	amount_point;

	amount_point = 0;
	if (fractol->type == 1)
		amount_point = mandelbrot(fractol, x, y);
	else if (fractol->type == 2)
		amount_point = julia(fractol, x, y);
	else if (fractol->type == 3)
		amount_point = newton_pool(fractol, x, y);
	return (amount_point);
}

void	fractol_color_definition(t_fractol *fractol)
{
	int	x;
	int	amount_point;
	int	color;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		amount_point = 0;
		while (x < WIN_WIDTH)
		{
			amount_point = fractol_type(fractol, x, y);
			color = get_rgb_smooth(fractol, amount_point, 0);
			if (amount_point != fractol->max_iteration)
				put_pixel(fractol->image.image, x, y, color);
			x++;
		}
		y++;
	}
}

void	fractol_color_definition_for_change(t_fractol *fr)
{
	int	x;
	int	amount_point;
	int	color;
	int	change_color;
	int	y;

	y = 0;
	change_color = fr->color.red + fr->color.green + fr->color.blue;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		amount_point = 0;
		color = change_color;
		while (x < WIN_WIDTH)
		{
			amount_point = fractol_type(fr, x, y);
			color = get_rgb_smooth(fr, amount_point, change_color);
			if (amount_point != fr->max_iteration)
				put_pixel(fr->image.image, x, y, color);
			x++;
		}
		y++;
	}
}
