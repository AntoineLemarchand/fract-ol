/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:47:46 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/15 10:20:43 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define RES_X 1200
# define RES_Y 1200
# define MAX_ITER 32
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
	int (*f)(float, float, t_data *));
int	ft_mandelbrot(float x, float y, t_data *data);
int	ft_julia(float x, float y, t_data *data);
int	ft_burningship(int x, int y);
#endif
