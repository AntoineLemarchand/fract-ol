/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:33:24 by antoine           #+#    #+#             */
/*   Updated: 2021/12/12 13:04:59 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(float x, float y)
{
	double	x0;
	double	y0;
	double	x2;
	double	y2;
	int		iter;

	x0 = (2.47 * x / RES_X - 2);
	y0 = (2.24 * y / RES_Y - 1.12);
	x = 0;
	y = 0;
	x2 = 0;
	y2 = 0;
	iter = 0;
	while ((x2 + y2) <= 4 && iter < MAX_ITER)
	{
		y = (x + x) * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
		iter++;
	}
	if (iter < 50)
		return (ft_getrgb(0, 0, (255 * iter) / 100, 0));
	else
		return (ft_getrgb(0, 0, 0, 0));
}

int	ft_julia(int x, int y)
{
	(void)x;
	(void)y;
	return (ft_getrgb(0, 0, 255, 0));
}

int	ft_burningship(int x, int y)
{
	(void)x;
	(void)y;
	return (ft_getrgb(0, 0, 0, 255));
}
