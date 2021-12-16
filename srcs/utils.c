/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:24:13 by antoine           #+#    #+#             */
/*   Updated: 2021/12/16 22:18:17 by antoine          ###   ########.fr       */
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

int	ft_fill_screen(t_data *data, int width, int height,
	int (*f)(float, float, float, float, t_data *))
{
	float	i;
	float	j;

	i = 0;
	j = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
				ft_putpix(data, i, j,
						f(i + data->offsetx * data->zoom,
						j + data->offsety * data->zoom, 0, 0, data));
				j++;
		}
		i++;
	}
	return (0);
}
