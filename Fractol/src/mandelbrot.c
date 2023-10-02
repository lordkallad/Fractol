/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuriens <rjuriens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:22:48 by rjuriens          #+#    #+#             */
/*   Updated: 2023/10/02 11:56:25 by rjuriens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	suite(t_complex z, t_complex c)
{
	z = mult_complex(z, z);
	z = add_complex (z, c);
	return (z);
}

int		iterate(t_complex c)
{
	int			i;
	t_complex	tmp;

	i = 0;
	tmp.re = 0;
	tmp.im = 0;
	while(i <= MAX_ITER)
	{
		tmp = suite(tmp, c);
			if(sqrt(pow(tmp.re, 2) + pow(tmp.im, 2) > 2))
				break ;
		i++;
	}
	return (i);
}