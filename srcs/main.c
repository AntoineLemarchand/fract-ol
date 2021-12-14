/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:54:28 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/14 17:40:23 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static int	mlx_draw_func(t_data *data)
{
	void	*func;

	if (!ft_strncmp(data->fractal, "-mandelbrot", 12))
		func = &ft_mandelbrot;
	else if (!ft_strncmp(data->fractal, "-julia", 7))
		func = &ft_julia;
	else
		func = &ft_burningship;
	ft_fill_screen(data, RES_X, RES_Y, func);
	return (0);
}

// 65307 = esc | <left/up/right/down> = 6536<1/2/3/4>
int	mlx_handlekb(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	else if (keycode == 65361)
		data->offsetx -= 25 / data->zoom;
	else if (keycode == 65362)
		data->offsety -= 25 / data->zoom;
	else if (keycode == 65363)
		data->offsetx += 25 / data->zoom;
	else if (keycode == 65364)
		data->offsety += 25 / data->zoom;
	if (keycode >= 65361 && keycode <= 65364)
	{
		mlx_draw_func(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}

// 4 = zoom | 5 = dezoom
int	mlx_handlemouse(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		data->zoom *= 1.25;
	else if (keycode == 5)
		data->zoom /= 1.25;
	if (keycode == 4 || keycode == 5)
	{
		mlx_draw_func(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}

int	ft_isparam(char *s)
{
	if (!ft_strncmp(s, "-mandelbrot", 12)
		|| !ft_strncmp(s, "-julia", 7)
		|| !ft_strncmp(s, "-burningship", 13))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || !ft_isparam(av[1]))
	{
		ft_putstr_fd("Available parameters:\n", 2);
		ft_putstr_fd("\t-mandelbrot\n\t", 2);
		ft_putstr_fd("-julia\n\t-burningship\n", 2);
		return (1);
	}
	data.fractal = av[1];
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, RES_X, RES_Y, av[1]);
	data.img = mlx_new_image(data.mlx, RES_X, RES_Y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	mlx_key_hook(data.win, mlx_handlekb, &data);
	mlx_mouse_hook(data.win, mlx_handlemouse, &data);
	data.offsetx = 0;
	data.offsety = 0;
	data.zoom = 1.05;
	mlx_draw_func(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
