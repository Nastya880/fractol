/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:19:21 by tandroma          #+#    #+#             */
/*   Updated: 2022/01/27 14:21:12 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include "key_macos.h"

# include <math.h>

/*
** Color
*/

typedef struct s_color
{
	int			red;
	int			green;
	int			blue;
}					t_color;

/*
** Complex number
** re — real part
** im — imaginary part
*/

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

/*
** Image
** bpp - bits_per_pixel — number of bits to represent a pixel color
** sizeline      		— number of bytes used to store one line of image
** endian — little or big endian - 0 = graphical sever is little endian, 
** 1 = big endian;
** image          		— image identifier
** data     			— the memory address of the image.
*/

typedef struct s_image
{
	int			bpp;
	int			sizeline;
	int			endian;
	void		*image;
	char		*data;
}		t_image;

/*
** Fractol
** image       			— information about image
** win         			— window identifier
** mlx            		— connection identifier
** zoom					- size of image in window
** start     			— start line of fractal part
** mouse				- place mouse in present moment
** max_iteration  		— maximum iteration
** color   				— the int color (0xTTRRGGBB);
** julia_c				- const complex number in Julia set
** type					- what type fractol (1, 2, 3)
*/

typedef struct s_fractol
{
	t_image		image;
	void		*win;
	void		*mlx;
	double		zoom;
	t_complex	start;
	t_complex	mouse;
	int			max_iteration;
	t_color		color;
	t_complex	julia_c;
	int			type;
}				t_fractol;

void	choose_type_fractol(int argc, char **argv_type, t_fractol *fractol);
void	create_window(t_fractol *fractol);
double	ft_atoi_double(const char *str);
void	print_arg(void);
void	fractol_print(t_fractol *fractol);
void	fractol_print_for_change_color(t_fractol *fractol);
int		key_hook(int keycode, t_fractol *param);
int		mouse_hook(int button, int x, int y, t_fractol *param);
int		red_cross(void);
void	fractol_color_definition(t_fractol *fractol);
void	fractol_color_definition_for_change(t_fractol *fractol);
int		mandelbrot(t_fractol *fractol, int x, int y);
int		julia(t_fractol *fractol, int x, int y);
int		newton_pool(t_fractol *fractol, int x, int y);

#endif
