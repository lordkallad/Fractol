/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:00:53 by marvin            #+#    #+#             */
/*   Updated: 2022/11/04 09:00:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	int		i;
	char	*dupstr;

	len = ft_strlen((char *)str);
	dupstr = malloc(sizeof(char) * len + 1);
	if (!dupstr)
		return (0);
	i = 0;
	while (str[i])
	{
		dupstr[i] = str[i];
		i++;
	}
	dupstr[i] = 0;
	return (dupstr);
}
