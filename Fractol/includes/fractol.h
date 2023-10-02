/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuriens <rjuriens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:41:41 by rjuriens          #+#    #+#             */
/*   Updated: 2023/10/02 13:50:37 by rjuriens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include "../minilibx/mlx.h"

# define WIN_WIDTH 500
# define WIN_HEIGHT 500
# define MAX_ITER 60
# define ZOOM 0.8
# define MOVE_OFFSET 0.1

typedef struct	s_data{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	double	x_offset;
	double	y_offset;
	double	zoom;
	int		bpp;
	int		line_len;
	int		endian;
} t_data;

typedef struct	s_complex{
	double	re;
	double	im;
}	t_complex;

void	draw_line(t_data data, int x, int y, int len);
void	draw_circle(void *data, int x, int y, int rad);
void	draw_fractal(t_data img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_complex	add_complex(t_complex c1, t_complex c2);
t_complex	mult_complex(t_complex c1, t_complex c2);
int		iterate(t_complex c);
int	ft_square(int n);
int	ft_abs(int n);
int	main(int argc, char **argv);
#endif