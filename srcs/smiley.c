/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smiley.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:54:28 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/10 12:27:31 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>

typedef struct	{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	float	x;
	float	y;
	float	i;

	x = 0;
	y = 0;
	i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (x < 2 * M_PI)
	{
		my_mlx_pixel_put(&img, (cos(x) * 200) + 400, (sin(x) * 200) + 400, 0x0000FF00);
		x += .001;
	}
	while (i < 100)
	{
		my_mlx_pixel_put(&img, 350, i++ + 250, 0x0000FF00);
		my_mlx_pixel_put(&img, 450, i++ + 250, 0x0000FF00);
	}
	while (y < M_PI)
	{
		my_mlx_pixel_put(&img, (cos(y) * 100) + 400, (sin(y) * 100) + 450, 0x0000FF00);
		y += .001;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
