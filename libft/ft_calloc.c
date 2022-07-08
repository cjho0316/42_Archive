/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:42:07 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/08 10:42:42 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *calloc(size_t count, size_t size)
{
    void *p;

    p = (void *)malloc(count*size);
    if (p == 0)
        return (0);
    ft_bzero(p, count*size);
    return(p);
}