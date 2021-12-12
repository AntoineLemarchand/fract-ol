/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:24:13 by antoine           #+#    #+#             */
/*   Updated: 2021/12/12 23:11:12 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putpix(t_data *data, int x, int y, int col)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data ->bits_per_pixel / 8));
	*(unsigned int *)dst = col;
}

int	ft_getrgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_fill_screen(t_data *data, int width, int length, int (*f)(int, int))
{
	float	i;
	float	j;

	i = 0;
	j = 0;
	while (i < width)
	{
		j = 0;
		while (j < length)
		{
			ft_putpix(data, i, j, f(i, j));
			j++;
		}
		i++;
	}
	return (0);
}
