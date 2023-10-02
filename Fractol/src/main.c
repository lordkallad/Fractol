/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuriens <rjuriens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:40:33 by rjuriens          #+#    #+#             */
/*   Updated: 2023/10/02 13:54:56 by rjuriens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


int	deal_key(int key, t_data *img)
{
	//printf("%d\n", key);
	if(key == 53)
		exit(0);
	else if(key == 123)//right
		img->x_offset -= MOVE_OFFSET * img->zoom;
	else if(key == 124)//left
		img->x_offset += MOVE_OFFSET * img->zoom;
	else if(key == 125)//up
		img->y_offset -= MOVE_OFFSET* img->zoom;
	else if(key == 126)//down
		img->y_offset += MOVE_OFFSET* img->zoom;
	else if(key == 69)
		img->zoom *= 0.7;
	else if (key == 78)
		img->zoom /= 0.7;
	else if(key == 7)
	{
		img->zoom = 1;
		img->x_offset = 0;
		img->y_offset = 0;
	}
	draw_fractal(*img);
	return(0);

}

int	deal_mouse(int key, int x, int y, t_data *img)
{
	if(key == 1)
	{
		mlx_mouse_get_pos(img->win, &x, &y);
		//draw_circle(img, x, y, 10);
		//draw_line(*img, x, y, 10);
		//printf("x = %d\ny = %d\n", x, y);
		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	}
	else if (key == 5)
		img->zoom += 0.1;
	else if (key == 4)
		img->zoom -= 0.1;
	draw_fractal(*img);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;
	t_data	img;
	int		*x;
	int		*y;

	x = malloc(sizeof(int *));
	y = malloc(sizeof(int *));
	mlx = mlx_init();
	img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	window = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Test");
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	img.win = window;
	img.mlx = mlx;
	img.x_offset = 0.0;
	img.y_offset = 0.0;
	img.zoom = 1.0;
	//mlx_pixel_put(mlx, win_ptr, 250, 250, 0xFF0000);
	//my_mlx_pixel_put(&img, 250, 250, 0xFF0000);
	
	//draw_circle(&img, WIN_WIDTH/2, WIN_HEIGHT/2, 100);
	draw_fractal(img);
	//mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_key_hook(window, deal_key, &img);
	mlx_mouse_hook(window, deal_mouse, &img);
	mlx_loop(mlx);
	(void)argc;
	(void)argv;
	return(0);
}
