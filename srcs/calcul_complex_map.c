/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_complex_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:17:10 by kahoumou          #+#    #+#             */
/*   Updated: 2024/02/19 16:41:15 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int x, int y, t_img_define *img, int color)
{
	int	offset;

	offset = (y * img->img_len) + (x * (img->pixels_bits / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

double	map(double unscaled_num, double new_min, double new_max,
		double old_max)
{
	double (old_min) = 0;
	return ((new_max - new_min) * (unscaled_num - old_min) / old_max + new_min);
}

t_complex_point	complex_sum(t_complex_point z1, t_complex_point z2)
{
	t_complex_point	result;

	result.x = z1.x + z2.x;
	result.y_i = z1.y_i + z2.y_i;
	return (result);
}

t_complex_point	square_complex(t_complex_point z)
{
	t_complex_point		result;

	result.x = (z.x * z.x) - (z.y_i * z.y_i);
	result.y_i = 2 * z.x * z.y_i;
	return (result);
}
