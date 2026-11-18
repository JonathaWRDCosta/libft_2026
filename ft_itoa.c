/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 21:42:26 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/18 00:55:50 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int		len;
	long	nb;

	len = 1;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		intlen;
	char	*str;
	long	nb;

	intlen = ft_intlen(n);
	str = ft_calloc(intlen + 1, sizeof(char));
	if (!str)
		return (NULL);
	nb = n;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (intlen > 0 && str[intlen - 1] != '-')
	{
		str[--intlen] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}