/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:54:00 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/13 20:47:47 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*t_src;
	char		*t_dest;

	t_src = src;
	t_dest = dst;
	if (size == 0)
		return (ft_strlen(src));
	while (*t_src && size > 1)
	{
		*t_dest = *t_src;
		t_dest++;
		t_src++;
		size--;
	}
	*t_dest = '\0';
	return (ft_strlen(src));
}
