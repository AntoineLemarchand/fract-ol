/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:54:28 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/10 14:55:10 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	mlx_handleinput(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
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
	t_vars	vars;

	if (ac != 2 || !ft_isparam(av[1]))
	{
		ft_putstr_fd("Available parameters:\n\t-mandelbrot\n\t\
-julia\n\t-burningship\n", 2);
		return (1);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Fract-ol");
	mlx_hook(vars.win, 2, 1L << 0, mlx_handleinput, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
