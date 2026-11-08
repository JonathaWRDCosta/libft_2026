/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:18:09 by jonatha           #+#    #+#             */
/*   Updated: 2026/11/08 22:35:12 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
    char memset[] = "Hello world memset";
    char bzero[] = "Hello world BZERO";
    char memcpy[] = "Hello world memcpy";
    char memcpy1[6] = "";

    printf("==============================================================\n");
    printf("ft_isprint(97) = %d\n", ft_isprint(97));
    printf("ft_isprint('\\n') = %d\n", ft_isprint('\n'));
    printf("==============================================================\n");
    printf("ft_isdigit(48) = %d\n", ft_isdigit(48));
    printf("ft_isdigit('\\n') = %d\n", ft_isdigit('\n'));
    printf("==============================================================\n");
    printf("ft_isalnum(48) = %d\n", ft_isdigit(48));
    printf("ft_isalnum('\\n') = %d\n", ft_isdigit('\n'));
    printf("==============================================================\n");
    printf("ft_isascii(48) = %d\n", ft_isascii(48));
    printf("ft_isascii('\\n') = %d\n", ft_isascii(128));
    printf("==============================================================\n");
    printf("ft_isalpha(48) = %d\n", ft_isalpha(97));
    printf("ft_isalpha('\\n') = %d\n", ft_isalpha('\n'));
    printf("==============================================================\n");
    printf("ft_strlen(Hello World!) = %d\n", ft_strlen("Hello World!"));
    printf("==============================================================\n");
    printf("ft_memset(Hello World!) , x, 5= %s\n", (char *)ft_memset(memset, 'x', 5));
    printf("==============================================================\n");
    ft_bzero(bzero, 5);
    printf("ft_bzero(Hello world BZERO), 5= %c\n", bzero[6]);
    printf("==============================================================\n");
    printf("ft_memcpy(Hello world memcpy) , xxxxx0, 5= %s\n", (char *)ft_memcpy(memcpy1, memcpy, 5));
    
    return (0);
}