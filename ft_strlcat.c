/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:35:09 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/13 21:30:28 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*t_src;
	char		*t_dst;
	size_t		i;

	i = 0;
	t_src = src;
	t_dst = dst;
	while (*t_dst && size > i)
	{
		t_dst++;
		i++;
	}
	if (size == i)
		return (size + ft_strlen(src));
	while (*t_src && size - 1 > i)
	{
		*t_dst = *t_src;
		t_dst++;
		t_src++;
		i++;
	}
	*t_dst = '\0';
	return (i + ft_strlen(t_src));
}
