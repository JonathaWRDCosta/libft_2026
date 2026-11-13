/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:42:02 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/13 20:47:41 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*t_s1;
	const unsigned char	*t_s2;

	t_s1 = (const unsigned char *)s1;
	t_s2 = (const unsigned char *)s2;
	while (n > 0 && *t_s1 && *t_s1 == *t_s2)
	{
		t_s1++;
		t_s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*t_s1 - *t_s2);
}
