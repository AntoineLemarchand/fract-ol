/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:43:59 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/16 22:34:33 by antoine          ###   ########.fr       */
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

int	ft_mandelbrot(float zx, float zy, float cx, float cy, t_data *data)
{
	float	zx2;
	float	zy2;
	int		iter;

	cx = (zx - RES_X / 2) / (.4 * (data->zoom * RES_X)) - .75;
	cy = (zy - RES_Y / 2) / (.4 * (data->zoom * RES_Y));
	zx = 0;
	zy = 0;
	zx2 = 0;
	zy2 = 0;
	iter = 0;
	if (ft_isbulb(cx, cy))
		return (0);
	while ((zx2 + zy2) <= 4 && iter < MAX_ITER)
	{
		zy = (zx + zx) * zy + cy;
		zx = zx2 - zy2 + cx;
		zx2 = zx * zx;
		zy2 = zy * zy;
		iter++;
	}
	return (ft_colorgraph(iter));
}

int	ft_julia(float zx, float zy,float cx, float cy, t_data *data)
{
	float	zx2;
	float	zy2;
	int		iter;

	if (!cx)
		cx=  .5;
	zx = 1.5 * (zx - RES_X / 2) / (.5 * (data->zoom * RES_X));
	zy = (zy - RES_Y / 2) / (.5 * (data->zoom * RES_Y));
	zx2 = zx * zx;
	zy2 = zy * zy;
	iter = 0;
	while ((zx2 + zy2) <= 4 && iter < MAX_ITER)
	{
		zy = (zx + zx) * zy + cy;
		zx = zx2 - zy2 + cx;
		zx2 = zx * zx;
		zy2 = zy * zy;
		iter++;
	}
	return (ft_colorgraph(iter));
}

int	ft_choufleur(float zx, float zy, float cx, float cy, t_data *data)
{
	cx = .285;
	return(ft_julia(zx, zy, cx, cy, data));
}
