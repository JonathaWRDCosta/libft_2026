/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:24:49 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/08 21:12:53 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *ptr = (unsigned char *)s;

    while (n > 0)
    {
        *ptr = (unsigned char)c;
        n--;
        ptr++;
    }
    return(s);
}