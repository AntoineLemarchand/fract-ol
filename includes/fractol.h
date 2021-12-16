/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:47:46 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/16 22:32:50 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define RES_X 800
# define RES_Y 800
# define MAX_ITER 50
# include <mlx.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	char	*fractal;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		offsetx;
	int		offsety;
	float	zoom;
}				t_data;
int	ft_getcol(int hue);
int	ft_fill_screen(t_data *data, int width, int height,
	int (*f)(float, float, float, float, t_data *));
int	ft_mandelbrot(float zx, float zy, float cx, float cy,t_data *data);
int	ft_julia(float zx, float zy, float cx, float xy, t_data *data);
int	ft_choufleur(float zx, float zy, float cx, float cy, t_data *data);
#endif
