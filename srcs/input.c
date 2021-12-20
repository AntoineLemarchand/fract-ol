/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:06:55 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/20 15:54:25 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"
#include<stdio.h>

int	mlx_handlekb(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	else if (keycode == LEFT)
		data->offsetx -= 25 / data->zoom;
	else if (keycode == UP)
		data->offsety -= 25 / data->zoom;
	else if (keycode == RIGHT)
		data->offsetx += 25 / data->zoom;
	else if (keycode == DOWN)
		data->offsety += 25 / data->zoom;
	mlx_draw_func(data, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	mlx_handlemouse(int keycode, int x, int y, t_data *data)
{
	float	cx;
	float	cy;

	if (keycode == SCROLLUP)
		data->zoom *= 1.25;
	else if (keycode == SCROLLDOWN)
		data->zoom /= 1.25;
	if (keycode == 4 || keycode == 5)
	{
		mlx_draw_func(data, 0, 0);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (keycode == 1)
	{
		cx = 2 * ((float)x - RES_X / 2) / RES_X;
		cy = 2 * ((float)y - RES_Y / 2) / RES_Y;
		mlx_draw_func(data, cx, cy);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}
