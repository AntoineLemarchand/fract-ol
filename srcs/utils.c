/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:24:13 by antoine           #+#    #+#             */
/*   Updated: 2021/12/13 23:52:07 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_putpix(t_data *data, int x, int y, int col)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data ->bits_per_pixel / 8));
	*(unsigned int *)dst = col;
	return (col);
}

int	ft_fill_screen(t_data *data, int width, int height,
	int (*f)(float, float, t_data *))
{
	float	i;
	float	j;
	int		col;

	i = 0;
	j = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			col = ft_putpix(data, i, j, f(i + data->offsetx,
						j++ + data->offsety, data));
			if (col == 0)
				ft_putpix(data, i, j++, col);
		}
		i++;
	}
	return (0);
}
