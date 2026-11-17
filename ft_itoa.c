/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 21:42:26 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/17 22:17:33 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_itoa(int n)
{
    size_t i;
    long num;
    char *result;
    i = 0;
    num = n;

    if (n == 0)
        i = 1;
    if (num < 0)
        num = num * -1;
    while (num > 0)
    {
        num = num / 10;
        i++;
    }
    if (n < 0)
        i = i + 1;
    result = malloc((i + 1) * sizeof(char));
    if(!result)
        return(NULL);
    num = n;
    result[i] = '\0';
    while (--i >= 0)
    {
        result[i] = num % 10 + '0';
        num--;
    }
}
