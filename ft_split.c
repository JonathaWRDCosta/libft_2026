/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:46:44 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/17 21:40:54 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *str, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

static void	ft_free(char **str, size_t to_free)
{
	size_t	k;

	k = 0;
	while (k < to_free)
	{
		free(str[k]);
		k++;
	}
	free(str);
}

static void	ft_copyword(char *dest, const char *src, size_t len)
{
	size_t	k;

	k = 0;
	while (k < len)
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = '\0';
}

static char	**ft_tofill(const char *str, char c, char **result, size_t words)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	start = 0;
	j = 0;
	while (words > j)
	{
		while (str[i] && str[i] == c)
			i++;
		start = i;
		while (str[i] && str[i] != c)
			i++;
		result[j] = malloc(((i - start) + 1) * sizeof(char));
		if (!result[j])
		{
			ft_free(result, j);
			return (NULL);
		}
		ft_copyword(result[j], &str[start], i - start);
		j++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**result;

	words = ft_countwords(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (ft_tofill(s, c, result, words));
}
