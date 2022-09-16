/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:04:45 by jang-cho          #+#    #+#             */
/*   Updated: 2022/09/16 20:08:30 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*p;
	size_t		len1;
	size_t		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = malloc(len1 + len2 + 1);
	if (p == 0)
		return (0);
	ft_strlcpy(p, s1, len1 + 1);
	ft_strlcat(p + len1, s2, len2 + 1);
	return (p);
}