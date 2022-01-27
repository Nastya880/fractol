/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fractols.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:04:48 by tandroma          #+#    #+#             */
/*   Updated: 2022/01/27 14:09:53 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static int	square_complex_point(t_fractol *fractol, t_complex z, t_complex c)
{
	double	tmp;
	int		ind;

	ind = -1;
	while (z.re * z.re + z.im * z.im <= 4 && ++ind < fractol->max_iteration)
	{
		tmp = z.re;
		z.re = tmp * tmp - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
	}
	return (ind);
}

static t_complex	init_complex_term(t_fractol *fr, int x, int y)
{
	t_complex	zoom;
	t_complex	mouse;
	t_complex	c;

	zoom.re = 0.5 * fr->zoom * WIN_WIDTH;
	zoom.im = 0.5 * fr->zoom * WIN_HEIGHT;
	mouse.re = fr->mouse.re / WIN_WIDTH;
	mouse.im = fr->mouse.im / WIN_HEIGHT;
	c.re = 1.6 *(x - WIN_WIDTH / 2) / zoom.re + mouse.re - 0.7;
	c.im = 1.6 * (y - WIN_HEIGHT / 2) / zoom.im - mouse.im;
	return (c);
}

int	mandelbrot(t_fractol *fractol, int x, int y)
{
	t_complex	c;
	t_complex	z;

	z.re = 0;
	z.im = 0;
	c = init_complex_term(fractol, x, y);
	return (square_complex_point(fractol, z, c));
}

int	julia(t_fractol *fractol, int x, int y)
{
	t_complex	z;

	z = init_complex_term(fractol, x, y);
	return (square_complex_point(fractol, z, fractol->julia_c));
}

int	newton_pool(t_fractol *fractol, int x, int y)
{
	int			i;
	double		tmp;
	t_complex	z;
	t_complex	d;
	t_complex	t;

	i = -1;
	tmp = 0;
	z = init_complex_term(fractol, x, y);
	d = z;
	while (z.re * z.re + z.im * z.im <= 4 && i++ < fractol->max_iteration)
	{
		t = z;
		tmp = (t.re * t.re + t.im * t.im) * (t.re * t.re + t.im * t.im);
		z.re = (double)(2) / 3 * t.re + (t.re * t.re - t.im * t.im) / (3 * tmp);
		z.im = (double)(2) / 3 * t.im * (double)(1 - (double)t.re / tmp);
		d.re = (t.re - z.re);
		d.re = fabs(d.re);
		d.im = (t.im - z.im);
		d.im = fabs(d.im);
	}
	return (i);
}
