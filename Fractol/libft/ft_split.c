/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:23:07 by marvin            #+#    #+#             */
/*   Updated: 2023/01/19 09:23:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_w(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

static size_t	get_wend(char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	return (len);
}

static int	fill_tab(char **tab, char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			*tab = ft_substr(s, i, get_wend(s + i, c));
			if (!tab)
				return (0);
			tab++;
			i = i + get_wend(s + i, c) - 1;
		}
		i++;
	}
	if (count_w(s, c) != 0)
		tab++;
	tab = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = ft_calloc(sizeof(char *), count_w((char *)s, c) + 1);
	if (!tab)
		return (NULL);
	if (!fill_tab(tab, (char *) s, c))
		return (NULL);
	return (tab);
}
