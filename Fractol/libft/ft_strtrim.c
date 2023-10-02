/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:46:27 by marvin            #+#    #+#             */
/*   Updated: 2022/11/17 08:46:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*strstart(char *s, const char *set)
{
	int	i;

	i = 0;
	while (s[i] && in_set(s[i], set))
		i++;
	return (&s[i]);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*str;
	char	*finals;

	str = strstart((char *)s1, set);
	i = ft_strlen(str);
	while (i > 0 && in_set(str[i - 1], set))
		i--;
	finals = malloc(sizeof(char) * (i + 1));
	if (!finals)
		return (NULL);
	finals[i] = 0;
	i--;
	while (i >= 0)
	{
		finals[i] = str[i];
		i--;
	}
	return (finals);
}
