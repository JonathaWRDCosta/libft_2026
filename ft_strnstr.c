/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 19:44:33 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/13 21:38:22 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	const char	*t_big;
	const char	*t_cmp;
	const char	*t_little;

	if (*little == '\0')
		return ((char *)big);
	t_big = big;
	while (*t_big && len > 0)
	{
		i = 0;
		t_cmp = t_big;
		t_little = little;
		while (i < len && *t_little && *t_cmp == *t_little)
		{
			t_little++;
			t_cmp++;
			i++;
		}
		if (*t_little == '\0')
			return ((char *)t_big);
		t_big++;
		len--;
	}
	return (NULL);
}
