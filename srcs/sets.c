/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:43:59 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/17 08:54:08 by alemarch         ###   ########.fr       */
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
	float	q;

	q = (x - .25) * (x - .25) + y * y;
	if (q * (q + (x - .25)) <= .25 * y * y)
		return (1);
	return (0);
}

int	ft_mandelbrot(t_complex z, t_complex c, t_data *data)
{
	float	zx2;
	float	zy2;
	int		iter;

	c.real = (z.real - RES_X / 2) / (.4 * (data->zoom * RES_X)) - .75;
	c.imag = (z.imag - RES_Y / 2) / (.4 * (data->zoom * RES_Y));
	z.real = 0;
	z.imag = 0;
	zx2 = 0;
	zy2 = 0;
	iter = 0;
	if (ft_isbulb(c.real, c.imag))
		return (0);
	while ((zx2 + zy2) <= 4 && iter < MAX_ITER)
	{
		z.imag = (z.real + z.real) * z.imag + c.imag;
		z.real = zx2 - zy2 + c.real;
		zx2 = z.real * z.real;
		zy2 = z.imag * z.imag;
		iter++;
	}
	return (ft_colorgraph(iter));
}

int	ft_julia(t_complex z, t_complex c, t_data *data)
{
	float	zx2;
	float	zy2;
	int		iter;

	/* a retirer plus tard */
	if (!c.real)
	{
		c.real=  .3;
		c.imag=  .5;
	}
	/*                     */
	z.real = 1.5 * (z.real - RES_X / 2) / (.5 * (data->zoom * RES_X));
	z.imag = (z.imag - RES_Y / 2) / (.5 * (data->zoom * RES_Y));
	zx2 = z.real * z.real;
	zy2 = z.imag * z.imag;
	iter = 0;
	while ((zx2 + zy2) <= 4 && iter < MAX_ITER)
	{
		z.imag = (z.real + z.real) * z.imag + c.imag;
		z.real = zx2 - zy2 + c.real;
		zx2 = z.real * z.real;
		zy2 = z.imag * z.imag;
		iter++;
	}
	return (ft_colorgraph(iter));
}

int	ft_choufleur(t_complex z, t_complex c, t_data *data)
{
	c.real = .285;
	return (ft_julia(z, c, data));
}
