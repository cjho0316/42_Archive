/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:01:04 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/13 06:45:31 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;

	if ((dst == 0 && src == 0))
		return (0);
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (a < b)
		return (ft_memcpy(dst, src, len));
	while (len--)
		*(a + len) = *(b + len);
	return (dst);
}
