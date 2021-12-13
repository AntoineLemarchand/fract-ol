/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:47:46 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/13 15:44:06 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define RES_X 1000
# define RES_Y 1000
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
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		offsetx;
	int		offsety;
}				t_data;
void	ft_putpix(t_data *data, int x, int y, int col);
int		ft_getcol(int hue);
int		ft_fill_screen(t_data *data, int width, int height,
	int (*f)(float, float));
int		ft_mandelbrot(float x, float y);
int		ft_burningship(int x, int y);
int		ft_julia(int x, int y);
#endif
