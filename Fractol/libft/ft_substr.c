/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:02:04 by marvin            #+#    #+#             */
/*   Updated: 2022/11/04 13:02:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = start;
	if (start >= (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	j = ft_strlen((char *)s + start);
	if (len > j)
		len = j;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] && (i < len + start))
	{
		str[i - start] = s[i];
		i++;
	}
	str[i - start] = 0;
	return (str);
}
