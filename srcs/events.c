/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:44:03 by kahoumou          #+#    #+#             */
/*   Updated: 2024/02/22 18:02:57 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_init_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_new_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_init_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_equal)
		fractal->iteration_scale += 10;
	else if (keysym == XK_minus)
		fractal->iteration_scale -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_init_fractal *fractal)
{
	if (button == Button5 && x != y)
	{
		fractal->zoom *= 1.05;
	}
	else if (button == Button4 && x != y)
	{
		fractal->zoom *= 0.95;
	}
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_init_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = map(x, -2, +2, 800) * fractal->zoom
			+ fractal->shift_x;
		fractal->julia_x = map(y, +2, -2, 800) * fractal->zoom
			+ fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
