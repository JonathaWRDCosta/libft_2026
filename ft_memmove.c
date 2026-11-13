/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 22:37:15 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/13 20:47:48 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*t_dest;
	const unsigned char	*t_src;

	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n--)
	{
		t_dest[n] = t_src[n];
	}
	return (dest);
}
