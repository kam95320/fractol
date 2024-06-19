/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:47:02 by kahoumou          #+#    #+#             */
/*   Updated: 2024/04/18 14:43:44 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	error(void)
{
	write(1, "malloc problems\n", 17);
	exit(EXIT_FAILURE);
}

static void	data_init(t_init_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iteration_scale = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	event_init(t_init_fractal *fractal)
{
	mlx_hook(fractal->mlx_new_window, KeyPress, KeyPressMask, key_handler,
		fractal);
	mlx_hook(fractal->mlx_new_window, ButtonPress, ButtonPressMask,
		mouse_handler, fractal);
	mlx_hook(fractal->mlx_new_window, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
}

void	fractal_init(t_init_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		error();
	fractal->mlx_new_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (NULL == fractal->mlx_new_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error();	
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_new_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.pixels_bits, &fractal->img.img_len,
			&fractal->img.endian_color);
	data_init(fractal);
	event_init(fractal);
}
