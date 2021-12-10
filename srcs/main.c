/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:54:28 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/10 12:23:32 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include <unistd.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	my_mlx_close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0'
		&& (unsigned char)s1[i] == (unsigned char)s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, (char *)s, 1);
		s++;
	}
}

int ft_isparam(char *s)
{
	if (!ft_strncmp(s, "-mandelbrot", 11)
		|| !ft_strncmp(s, "-julia", 6)
		|| !ft_strncmp(s, "-burningship", 12))
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
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, my_mlx_close, &vars);
	mlx_loop(vars.mlx);
}
