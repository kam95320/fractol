/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:29:52 by kahoumou          #+#    #+#             */
/*   Updated: 2024/02/21 16:29:53 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>
#include <stdint.h>

static void	sort_fract(t_complex_point *z, t_complex_point *c,
		t_init_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y_i = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y_i = z->y_i;
	}
}

void	handle(int x, int y, t_init_fractal *fractal)
{
	t_complex_point	z;
	t_complex_point	c;
	int				i;
	int				color;

	i = 0;
	z.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y_i = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	sort_fract(&z, &c, fractal);
	while (i < fractal->iteration_scale)
	{
		z = complex_sum(square_complex(z), c);
		if ((z.x * z.x) + (z.y_i * z.y_i) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iteration_scale);
			my_pixel_put(x, y, &fractal->img, colori(i));
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, colori(i));
}

void	fractal_render(t_init_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_new_window,
		fractal->img.img_ptr,
		0,
		0);
}
