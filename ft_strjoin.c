/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:22:16 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/14 19:31:36 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *t_newstr;
    size_t i;

    i = ft_strlen(s1) + ft_strlen(s2);

    t_newstr = malloc(i + 1);
    if (t_newstr == NULL)
        return(NULL);
    i = 0;
    while (*s1)
    {
        t_newstr[i] = *s1;
        i++;
        s1++;   
    }
    while (*s2)
    {
        t_newstr[i] = *s2;
        i++;
        s2++;
    }
    t_newstr[i] = '\0';
    return(t_newstr);
}
