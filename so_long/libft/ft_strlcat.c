/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 08:27:21 by jangchoi          #+#    #+#             */
/*   Updated: 2022/07/13 07:53:50 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	ssize;
	size_t	dsize;
	size_t	i;

	i = 0;
	ssize = ft_strlen(src);
	dsize = ft_strlen(dest);
	if (size == 0)
		return (size + ssize);
	else if (size <= dsize)
		return (size + ssize);
	else if (size > dsize)
	{
		while (dsize + i < size - 1 && src[i] != '\0')
		{
			dest[dsize + i] = src[i];
			i++;
		}
	}
	dest[dsize + i] = '\0';
	return (dsize + ssize);
}
