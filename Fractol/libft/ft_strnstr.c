/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuriens <rjuriens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:48:07 by rjuriens          #+#    #+#             */
/*   Updated: 2022/10/31 12:57:03 by rjuriens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	char	*p;	
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (!*to_find)
		return (str);
	while (str[i] && i < len)
	{
		p = str + i;
		k = i;
		while (str[k] == to_find[j] && j + i < len)
		{
			k++;
			j++;
			if (to_find[j] == '\0')
				return (p);
		}
	j = 0;
	i++;
	}
	return (NULL);
}
