/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 05:01:10 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/11 16:50:52 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
    

    if (dstsize == 0)
    {
        return(ft_strlen(src));
    }
    
    while (*src)
    {
        if (dstsize > 0)
        {
            *dst = *src;
            dst++;
            src++;
        }
    }
    *dst = ''
}