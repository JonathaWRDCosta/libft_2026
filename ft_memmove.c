/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 22:37:15 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/10 04:53:54 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    const unsigned char *ptrSrc = src;
    unsigned char *ptrDest = dest;
    
    if (n == 0)
        return(dest);

    if (dest < src)
    {
        while (n > 0)
        {
            *ptrDest = *ptrSrc;
            ptrDest++;
            ptrSrc++;
            n--;
        }
    }
    else
    {
        ptrDest += n - 1;
        ptrSrc += n - 1;
        while (n > 0)
        {
            n--;
            *ptrDest = *ptrSrc;
            if (n > 0)
            {
                ptrDest--;
                ptrSrc--;
            }
        }
    }
    return(dest);
}