/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:54:28 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/10 20:42:08 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	mlx_handleinput(int keycode, t_data *data)
{
	if (keycode == 65307)
		mlx_destroy_window(data->mlx, data->win);
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

int	mlx_draw_func(t_data *data, char *set)
{
	void	*func;

	if (!ft_strncmp(set, "-mandelbrot", 12))
		func = &ft_mandelbrot;
	else if (!ft_strncmp(set, "-julia", 7))
		func = &ft_julia;
	else
		func = &ft_burningship;
	ft_fill_screen(data, RES_X, RES_Y, func);
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
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 600, ft_strtrim(av[1], "-"));
	data.img = mlx_new_image(data.mlx, 800, 600);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	mlx_hook(data.win, 2, 1L << 0, mlx_handleinput, &data);
	mlx_draw_func(&data, av[1]);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
