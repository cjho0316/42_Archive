/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:50:24 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/07 20:07:58 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    if (s == 0)
        return (0);

    while (n)
    {
        if ((unsigned char *)s == (unsigned char)c)
            return((void *)s);
        *s++;
        n--;
    }
    return(0);
}