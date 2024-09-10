/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-06 11:35:21 by selango           #+#    #+#             */
/*   Updated: 2024-09-06 11:35:21 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		fractal.name = argv[1];
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		if (!float_checker(argv[2]) || !float_checker(argv[3]))
			error_msg();
		fractal.name = argv[1];
		fractal.julia_x = atodbl(argv[2]);
		fractal.julia_y = atodbl(argv[3]);
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);
}
