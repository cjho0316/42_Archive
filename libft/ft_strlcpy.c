/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:25:27 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/08 09:36:53 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen1(char *src)
{
	int	j;

	j = 0;
	while (src[j] != 0)
		j++;
	return (j);
}

unsigned int	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	s;

	s = ft_strlen1(src);
	i = 0;
	if (size == 0)
		return (s);
	else
	{
		while (i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (s);
}
