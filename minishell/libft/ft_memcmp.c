/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:13:22 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/13 17:20:04 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			idx;
	unsigned char	*p1;
	unsigned char	*p2;

	idx = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (idx < n)
	{
		if (p1[idx] == p2[idx])
			idx++;
		else
			return (p1[idx] - p2[idx]);
	}
	return (0);
}
