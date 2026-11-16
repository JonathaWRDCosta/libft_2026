/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:46:44 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/16 20:30:26 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_split(char const *s, char c)
{
    char **result;
    size_t words;
    size_t start;
    size_t len;;
    size_t i;
    size_t j;
    size_t k;


    i = 0;
    j = 0;
    words = 0;
    if (!s)
        return(NULL);
    while (s[i])
    {
        if (s[i] != c && (i == 0 || s[i - 1] == c))
            words++;
        i++;
    }
    result = malloc((words + 1) * (sizeof(char *)));
    if (!result)
        return(NULL);
    i = 0;
    while (s[i] && s[i] == c)
        i++;
    start = i;
    while (s[i] && s[i] != c)
        i++;
    len = i - start;
    result[j] = malloc((len + 1) * sizeof(char));
    if(!result[j])
        return(NULL);
    k = 0;
    while (k < len)
    {
        result[j][k] = s[start + k];
        k++;
    }
    result[j][k] = '\0';
}

