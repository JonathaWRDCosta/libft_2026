/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:17:28 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/13 22:01:39 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*t_ptr;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	t_ptr = malloc(nmemb * size);
	if (t_ptr == NULL)
		return (NULL);
	ft_bzero(t_ptr, nmemb * size);
	return (t_ptr);
}
