/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:24:13 by antoine           #+#    #+#             */
/*   Updated: 2021/12/17 11:24:23 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_putpix(t_data *data, int x, int y, int col)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data ->bits_per_pixel / 8));
	*(unsigned int *)dst = col;
}

int	ft_fill_screen(t_data *data, int (*f)(t_complex, t_complex, t_data *))
{
	float		i;
	float		j;
	t_complex	z;
	t_complex	c;

	i = 0;
	j = 0;
	while (i < RES_X)
	{
		j = 0;
		z.real = i + data->offsetx * data->zoom;
		while (j < RES_Y)
		{
			z.imag = j + data->offsety * data->zoom;
			c.real = 0;
			c.imag = 0;
			ft_putpix(data, i, j++, f(z, c, data));
		}
		i++;
	}
	return (0);
}
