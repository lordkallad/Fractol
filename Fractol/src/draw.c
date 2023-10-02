/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuriens <rjuriens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:01:27 by rjuriens          #+#    #+#             */
/*   Updated: 2023/10/02 13:26:12 by rjuriens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_line(t_data data, int x, int y, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		my_mlx_pixel_put(&data, x, y + i, 0x00FF00);
		i++;
	}
}

void	draw_circle(void *data, int x, int y, int rad)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < WIN_WIDTH)
	{
		while (j < WIN_HEIGHT)
		{
			if(ft_square(ft_abs(i - x)) + ft_square(ft_abs(j - y)) <= ft_square(rad))
				my_mlx_pixel_put(data, i, j, 0x00FF00);
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_point(int x, int y,  t_data img)
{
	int	i;
	t_complex	c;

	c.re = ((x - (WIN_WIDTH/2)) * ((4.0 / WIN_WIDTH * img.zoom))) + img.x_offset;
	c.im = -(((y - (WIN_HEIGHT/2)) * ((4.0 / WIN_HEIGHT * img.zoom)))) + img.y_offset;
	i = iterate(c);
	if (i >= MAX_ITER)
	{
		my_mlx_pixel_put(&img, x, y, 0x000000);
	}
	else
	{
		my_mlx_pixel_put(&img, x, y, (i % 32 + 64) << 12);
	}

}

void	draw_fractal(t_data img)
{
	double x;
	double y;

	x = 0;
	while (x < WIN_WIDTH) 
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			draw_point(x, y, img);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
}