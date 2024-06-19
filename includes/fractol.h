/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:59:12 by kahoumou          #+#    #+#             */
/*   Updated: 2024/02/21 16:59:19 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESSAGE "Please enter fractal name mandelbrot or julia\n\t\""

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000 // RGB(0, 0, 0)
# define WHITE 0xFFFFFF // RGB(255, 255, 255)
# define RED 0xFF0000   // RGB(255, 0, 0)
# define GREEN 0x00FF00 // RGB(0, 255, 0)
# define BLUE 0x0000FF  // RGB(0, 0, 255)

# define MAGENTA_BURST 0xFF00FF      // A vibrant magenta
# define LIME_SHOCK 0xCCFF00         // A blinding lime
# define NEON_ORANGE 0xFF6600        // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066 // A deep purple
# define AQUA_DREAM 0x33CCCC         // A bright turquoise
# define HOT_PINK 0xFF66B2           // As the name suggests!
# define ELECTRIC_BLUE 0x0066FF      // A radiant blue
# define LAVA_RED 0xFF3300           // A bright, molten red

typedef struct s_complex_point
{	
	double			x;

	double			y_i;
}					t_complex_point;

typedef struct s_img_define
{
	void			*img_ptr;
	char			*pixel_ptr;
	int				pixels_bits;
	int				endian_color;
	int				img_len;

}					t_img_define;

typedef struct s_init_fractal
{
	char			*name;
	char			*addr;
	void			*mlx_connection;
	void			*mlx_new_window;
	int				iteration_scale;
	double			escape_value;
	double			shift_x;
	double			shift_y;
	double			zoom;
	t_img_define	img;
	double			julia_x;
	double			julia_y;
}					t_init_fractal;

void				fractal_init(t_init_fractal *fractal);
void				fractal_render(t_init_fractal *fractal);
void				handle(int x, int y, t_init_fractal *fractal);
t_complex_point		complex_sum(t_complex_point z1, t_complex_point z2);
t_complex_point		square_complex(t_complex_point z);

double				map(double unscaled_num, double new_min, double new_max,
						double old_max);

int					key_handler(int keysym, t_init_fractal *fractal);
int					mouse_handler(int button, int x, int y,
						t_init_fractal *fractal);
int					close_handler(t_init_fractal *fractal);
double				atodbl(char *s);
int					julia_track(int x, int y, t_init_fractal *fractal);
void				my_pixel_put(int x, int y, t_img_define *img, int color);
double				atodbl(char *s);
int					colori(int color);
double				atodbl(char *s);
int					ft_strcmp(char *s1, char *s2);

#endif