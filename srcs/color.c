/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:00:54 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/13 14:26:23 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * HUE TO RGB
 *
 * R = 255        on [:16] & [84:]
 *	 = 0          on [33:66]
 *   = 255 -> 0   on [16:33]
 *   = 0   -> 255 on [66:84]
 *
 * G = 255        on [16:50]
 *   = 0          on [66:]
 *   = 255 -> 0   on [50:66]
 *   = 0   -> 255 on [:16]
 *
 * B = 255        on [50:84]
 *   = 0          on [:33]
 *   = 255 -> 0   on [84:]
 *   = 0   -> 255 on [33:50]
 */

static int	ft_getr(int hue)
{
	int	r;

	if (hue <= 16 || hue > 84)
		r = 255;
	else if (hue <= 33)
		r = 255 - ((255 * (hue - 16)) / 16);
	else if (hue <= 66)
		r = 0;
	else
		r = 255 * (hue - 66) / 16;
	return (r);
}

static int	ft_getg(int hue)
{
	int	g;

	if (hue <= 16)
		g = (255 * hue) / 16;
	else if (hue <= 50)
		g = 255;
	else if (hue <= 66)
		g = 255 - (255 * (hue - 50) / 16);
	else
		g = 0;
	return (g);
}

static int	ft_getb(int hue)
{
	int	b;

	if (hue <= 33)
		b = 0;
	else if (hue <= 50)
		b = (255 * (hue - 33) / 16);
	else if (hue <= 84)
		b = 255;
	else
		b = 255 - (255 * (hue - 84) / 16);
	return (b);
}

int	ft_getcol(int hue)
{
	int	r;
	int	g;
	int	b;

	r = ft_getr(hue);
	g = ft_getg(hue);
	b = ft_getb(hue);
	return (0 << 24 | r << 16 | g << 8 | b);
}
