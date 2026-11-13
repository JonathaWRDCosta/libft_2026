/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:44:45 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/13 20:47:42 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	t_chr;

	t_chr = c;
	while (*s)
	{
		if (t_chr == *s)
			return ((char *)s);
		s++;
	}
	if (t_chr == (unsigned char)*s)
		return ((char *)s);
	return (NULL);
}
