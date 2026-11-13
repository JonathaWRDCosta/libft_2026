/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 19:39:30 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/13 20:47:39 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t_str1;
	const unsigned char	*t_str2;

	t_str1 = s1;
	t_str2 = s2;
	while (n > 0 && *t_str1 == *t_str2)
	{
		n--;
		t_str1++;
		t_str2++;
	}
	if (n == 0)
		return (0);
	return (*t_str1 - *t_str2);
}
