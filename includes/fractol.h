/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:47:46 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/10 20:36:52 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define RES_X 800
# define RES_Y 600
# include <mlx.h>
# include <stddef.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
int	ft_mandelbrot(int x, int y);
int	ft_burningship(int x, int y);
int	ft_julia(int x, int y);
int	ft_fill_screen(t_data *data, int width, int length, int (*f)(int, int));
#endif
