/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:58:16 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/13 20:47:40 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*t_str = s;
	const unsigned char	t_char = c;

	while (n > 0)
	{
		if (*t_str == t_char)
			return ((void *)t_str);
		t_str++;
		n--;
	}
	return (NULL);
}
