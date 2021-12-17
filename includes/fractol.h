/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:47:46 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/17 08:54:59 by alemarch         ###   ########.fr       */
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
}	t_data;

typedef struct s_complex {
	float	real;
	float	imag;
}	t_complex;

int	ft_getcol(int hue);
int	ft_fill_screen(t_data *data, int width, int height,
		int (*f)(t_complex, t_complex, t_data *));
int	ft_mandelbrot(t_complex z, t_complex c, t_data *data);
int	ft_julia(t_complex z, t_complex c, t_data *data);
int	ft_choufleur(t_complex z, t_complex c, t_data *data);
#endif
