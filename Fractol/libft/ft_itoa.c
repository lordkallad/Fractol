/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:31:07 by marvin            #+#    #+#             */
/*   Updated: 2023/01/09 12:31:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int i)
{
	int	len;

	len = 1;
	while (i > 9)
	{
		i /= 10;
		len++;
	}
	return (len);
}

static void	filltab(char *tab, int n, int size, int neg)
{
	if (neg)
		tab[0] = '-';
	tab[size] = 0;
	size--;
	while (size >= 0 + neg)
	{
		tab[size] = n % 10 + '0';
		n /= 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	char	*fnum;
	int		neg;

	if (n == -2147483648)
	{
		fnum = malloc(sizeof(char) * 12);
		if (!fnum)
			return (0);
		filltab(fnum, 2147483647, 11, 1);
		fnum[10] = '8';
		return (fnum);
	}
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	else
		neg = 0;
	fnum = malloc(sizeof(char) * (numlen(n) + neg + 1));
	if (!fnum)
		return (0);
	filltab(fnum, n, numlen(n) + neg, neg);
	return (fnum);
}
