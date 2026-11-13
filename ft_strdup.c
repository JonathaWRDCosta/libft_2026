/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:17:32 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/13 22:13:52 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*t_str;
	size_t	i;

	i = ft_strlen(s);
	t_str = malloc(i + 1);
	if (t_str == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		t_str[i] = *s;
		i++;
		s++;
	}
	t_str[i] = '\0';
	return (t_str);
}
