/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:33:44 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/12 16:03:48 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (dst == 0 && src == 0)
		return (0);
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	while (n)
	{
		*a++ = *b++;
		n--;
	}
	return (dst);
}
