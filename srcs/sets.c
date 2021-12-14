/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:33:24 by antoine           #+#    #+#             */
/*   Updated: 2021/12/14 18:00:28 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_colorgraph(int val)
{
	int		nval;

	nval = (100 * val) / MAX_ITER;
	if (val == MAX_ITER)
		return (0);
	return (ft_getcol(nval));
}

static int	ft_isbulb(float x, float y)
{
	float q;

	q = (x - .25) * (x - .25) + y * y;
	if (q * (q + (x - .25)) <= .25 * y * y)
		return (1);
	return (0);
}

int	ft_mandelbrot(float x, float y, t_data *data)
{
	float	x0;
	float	y0;
	float	x2;
	float	y2;
	int		iter;

	x0 = ((2.47 * x) / RES_X - 2) / data->zoom;
	y0 = ((2.24 * y) / RES_Y - 1.12) / data->zoom;
	x = -.5;
	y = 0;
	x2 = 0;
	y2 = 0;
	iter = 0;
	if (ft_isbulb(x0, y0))
		return (0);
	while ((x2 + y2) <= 4 && iter < MAX_ITER)
	{
		y = (x + x) * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
		iter++;
	}
	return (ft_colorgraph(iter));
}

int	ft_julia(float x, float y, t_data *data)
{
	float	x0;
	float	y0;
	float	x2;
	float	y2;
	int		iter;

	x0 = ((2.47 * x) / RES_X - 2) / data->zoom;
	y0 = ((2.24 * y) / RES_Y - 1.12) / data->zoom;
	x = -.5;
	y = 0;
	x2 = 0;
	y2 = 0;
	iter = 0;
	if (ft_isbulb(x0, y0))
		return (0);
	while ((x2 + y2) <= 4 && iter < MAX_ITER)
	{
		y = (x + x) * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
		iter++;
	}
	return (ft_colorgraph(iter));
}

int	ft_burningship(int x, int y)
{
	(void)x;
	(void)y;
	return (0);
}
