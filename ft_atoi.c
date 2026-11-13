/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:22:41 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/13 20:51:23 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		j;
	long	result;

	j = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			j *= -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		result = result * 10 + *nptr - 48;
		nptr++;
	}
	return (result * j);
}
