/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:47:46 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/20 17:01:49 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
// affichage
# define MAX_ITER 50
# define RES_X 800
# define RES_Y 800
// input clavier
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define ESC 65307
// input souris
# define SCROLLUP 4
# define SCROLLDOWN 5
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
	float	cx;
	float	cy;
}	t_data;

typedef struct s_complex {
	float	real;
	float	imag;
}	t_complex;

int	mlx_draw_func(t_data *data);
int	mlx_handlekb(int keycode, t_data *data);
int	mlx_handlemouse(int keycode, int x, int y, t_data *data);
int	ft_getcol(int hue);
int	ft_fill_screen(t_data *data, int (*f)(t_complex, t_complex, t_data *),
		float cx, float cy);
int	ft_mandelbrot(t_complex z, t_complex c, t_data *data);
int	ft_julia(t_complex z, t_complex c, t_data *data);
int	ft_choufleur(t_complex z, t_complex c, t_data *data);
#endif
