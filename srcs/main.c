/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:54:28 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/20 16:59:54 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	mlx_draw_func(t_data *data)
{
	if (!ft_strncmp(data->fractal, "mandelbrot", 11))
		ft_fill_screen(data, &ft_mandelbrot, 0, 0);
	else if (!ft_strncmp(data->fractal, "chou-fleur", 6))
		ft_fill_screen(data, &ft_choufleur, 0, 0);
	else
		ft_fill_screen(data, &ft_julia, data->cx, data->cy);
	return (0);
}

int	ft_isparam(char *s)
{
	if (!ft_strncmp(s, "mandelbrot", 12)
		|| !ft_strncmp(s, "julia", 7)
		|| !ft_strncmp(s, "chou-fleur", 11))
		return (1);
	return (0);
}

void	ft_initdata(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, RES_X, RES_Y, data->fractal);
	data->img = mlx_new_image(data->mlx, RES_X, RES_Y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->offsetx = 0;
	data->offsety = 0;
	data->cx = .285;
	data->cy = .5;
	data->zoom = 1.05;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || !ft_isparam(av[1]))
	{
		ft_putstr_fd("Available parameters:\n", 2);
		ft_putstr_fd("\t* mandelbrot\n\t", 2);
		ft_putstr_fd("* julia\n\t* chou-fleur\n", 2);
		return (22);
	}
	data.fractal = av[1];
	ft_initdata(&data);
	mlx_key_hook(data.win, mlx_handlekb, &data);
	mlx_mouse_hook(data.win, mlx_handlemouse, &data);
	mlx_draw_func(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
