/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:33:24 by antoine           #+#    #+#             */
/*   Updated: 2021/12/10 20:41:31 by antoine          ###   ########.fr       */
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

int	ft_mandelbrot(int x, int y)
{
	(void)x;
	(void)y;
	return (0x00FF0000);
}

int	ft_julia(int x, int y)
{
	(void)x;
	(void)y;
	return (0x0000FF00);
}

int	ft_burningship(int x, int y)
{
	(void)x;
	(void)y;
	return (0x000000FF);
}

int	ft_fill_screen(t_data *data, int width, int length, int (*f)(int, int))
{
	int	i;
	int	j;

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
