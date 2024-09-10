/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-04 13:31:55 by selango           #+#    #+#             */
/*   Updated: 2024-09-04 13:31:55 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int (*f)(int keycode, void *param);
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	static int	shift_pressed = 0;

	if (keysym == XK_Shift_L || keysym == XK_Shift_R)
		shift_pressed = 1;
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if ((shift_pressed && keysym == XK_equal) || (keysym == XK_KP_Add))
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button4)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button5)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, 2, WIDTH) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia_y = (map(y, 2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
	}
	fractal_render(fractal);
	return (0);
}
