/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:00:55 by kahoumou          #+#    #+#             */
/*   Updated: 2024/02/19 17:20:18 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_putstr_fd (ERROR_MESSAGE, STDERR_FILENO);
	exit (EXIT_FAILURE);
}

int	init_fractal(t_init_fractal	fractal)
{
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (1);
}

int	main(int argc, char *argv[], char **envp)
{
	t_init_fractal	fractal;

	if (envp == NULL)
		return (0);
	if ((2 == argc && !ft_strcmp(argv[1], "mandelbrot")) || (2 == argc
			&& !ft_strcmp(argv[1], "julia")) || (4 == argc
			&& !ft_strcmp(argv[1], "julia")))
	{
		fractal.name = argv[1];
		if (2 == argc && !ft_strncmp(argv[1], "julia", 5))
		{
			argv[2] = "-0.8";
			argv[3] = "+0.150";
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		if (4 == argc && !ft_strncmp(argv[1], "julia", 5))
		{
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		init_fractal(fractal);
	}
	else
		ft_error ();
}
