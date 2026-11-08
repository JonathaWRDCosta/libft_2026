/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 22:03:37 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/08 22:28:38 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    const unsigned char *ptrSrc = src;
    unsigned char *ptrDest = dest;

    while (n > 0)
    {
        *ptrDest = *ptrSrc;
        ptrDest++;
        ptrSrc++;
        n--;
    }
    return(dest);
}