/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-03 10:20:09 by selango           #+#    #+#             */
/*   Updated: 2024-09-03 10:20:09 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MSG \
	"Please enter \n\t\"./fractal mandelbrot\" \
					or \n\t\"./fractal julia <value 1> <value 2>\"\n"
# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000   // RGB(0, 0, 0)
# define WHITE 0xFFFFFF   // RGfractolB(255, 255, 255)
# define RED 0xFF0000     // RGB(255, 0, 0)
# define GREEN 0x00FF00   // RGB(0, 255, 0)
# define BLUE 0x0000FF    // RGB(0, 0, 255)
# define YELLOW 0xFFFF00  // RGB(255, 255, 0)
# define CYAN 0x00FFFF    // RGB(0, 255, 255)
# define MAGENTA 0xFF00FF // RGB(255, 0, 255)
# define GRAY 0x808080    // RGB(128, 128, 128)
# define ORANGE 0xFFA500  // RGB(255, 165, 0)

// Complex value
typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

// fractal id ,mlx, hooks_value
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_length;
}			t_img;

typedef struct s_fractal
{
	char	*name;

	void	*mlx_connection;
	void	*mlx_window;
	// image
	t_img	img;
	// hooks member variables
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;

}			t_fractal;

size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
double		atodbl(char *s);
void		error_msg(void);
// map fn
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			float_checker(char *s);
int			ft_isdigit(char c);

int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);

#endif