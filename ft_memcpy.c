/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 22:03:37 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/13 21:34:27 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*t_src;
	unsigned char		*t_dest;

	t_src = src;
	t_dest = dest;
	if (t_src == NULL && t_dest == NULL)
		return (dest);
	while (n > 0)
	{
		*t_dest = *t_src;
		t_dest++;
		t_src++;
		n--;
	}
	return (dest);
}
