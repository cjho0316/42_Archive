/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:13:22 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/07 20:23:30 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    while (s1 && s2 && n)
    {
        if ((unsigned char *)s1 == (unsigned char *)s2)
        {
            *s1++;
            *s2++;
            n--;
        }
        else
            return ((unsigned char *)s1 - (unsigned char *)s2);
    }
    return (0);
}