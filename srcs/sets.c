/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:33:24 by antoine           #+#    #+#             */
/*   Updated: 2021/12/14 14:14:57 by alemarch         ###   ########.fr       */
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

int	ft_mandelbrot(float x, float y, t_data *data)
{
	double	x0;
	double	y0;
	double	x2;
	double	y2;
	int		iter;

	x0 = ((2.47 * data->zoom * x) / RES_X - 2) / data->zoom;
	y0 = ((2.24 * y * data->zoom) / RES_Y - 1.12) / data->zoom;
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
	return (ft_colorgraph(iter));
}

int	ft_julia(float x, float y, t_data *data)
{
	double	x0;
	double	y0;
	double	x2;
	double	y2;
	int		iter;
	float	t;

	t = .02;
	x0 = sin(t * .8);
	y0 = sin(t);
	x2 = 0;
	y2 = 0;
	x = x * data->zoom;
	y = y * data->zoom;
	iter = 0;
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
