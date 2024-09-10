/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-06 11:36:34 by selango           #+#    #+#             */
/*   Updated: 2024-09-06 11:36:34 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min)
		+ new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	float_checker(char *s)
{
	int	dot_count;

	dot_count = 0;
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (*s == '.')
		{
			if (dot_count > 0)
				return (0);
			dot_count++;
		}
		else if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}
