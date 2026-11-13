/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:59:52 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/13 20:47:51 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*t_str;
	unsigned char	t_chr;

	t_str = s;
	t_chr = c;
	while (*s)
		s++;
	while (s >= t_str)
	{
		if (t_chr == (unsigned char)*s)
			return ((char *)s);
		if (t_str == s)
			return (NULL);
		s--;
	}
	return (NULL);
}
