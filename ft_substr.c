/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 22:18:14 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/14 19:18:45 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*t_sub;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	t_sub = malloc(len + 1);
	if (t_sub == NULL)
		return (NULL);
	s = s + start;
	while (i < len && *s)
	{
		t_sub[i] = *s;
		i++;
		s++;
	}
	t_sub[i] = '\0';
	return (t_sub);
}
