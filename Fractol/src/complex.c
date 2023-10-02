/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuriens <rjuriens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:52:14 by rjuriens          #+#    #+#             */
/*   Updated: 2023/09/26 13:22:20 by rjuriens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


t_complex	add_complex(t_complex c1, t_complex c2)
{
	t_complex	result;
	result.re = c1.re + c2.re;
	result.im = c1.im + c2.im;

	return (result);
}

t_complex	mult_complex(t_complex c1, t_complex c2)
{
	t_complex	result;

	result.re = (c1.re * c2.re) - (c1.im * c2.im);
	result.im = (c1.re * c2.im) + (c1.im * c2.re);
	return (result); 
}
