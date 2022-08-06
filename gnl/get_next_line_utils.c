/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 02:43:59 by jang-cho          #+#    #+#             */
/*   Updated: 2022/08/06 17:10:45 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup1(const char *src)
{
	int		i;
	int		ssize;
	char	*dest;

	i = 0;
	ssize = 0;
	while (src[ssize] != '\0')
		ssize++;
	dest = (char *)malloc(sizeof(char) * (ssize + 1));
	if (dest == 0)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_strlcpy1(char *dst, const char *src, size_t size)
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
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char		*p;
	size_t		len1;
	size_t		len2;

	if (s1 == 0)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	len1 = ft_strlen1(s1);
	len2 = ft_strlen1(s2);
	p = malloc(len1 + len2 + 1 + 1);
	if (p == 0)
		return (0);
	ft_strlcpy1(p, s1, len1 + 1);
	ft_strlcpy1(p + len1, s2, len2 + 1);
	free(s1);
	return (p);
}

int	ft_strchr_idx(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
