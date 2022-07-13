/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:12:23 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/13 18:44:43 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*p1;
	const char	*p2;

	if (*haystack == 0)
		return (0);
	if (len == 0 || ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && len--)
	{
		p1 = haystack;
		p2 = needle;
		while (*p1 != '\0' && *p2 != '\0' && (*p1 == *p2))
		{
			if ((haystack + len) == p1)
				break ;
			p1++;
			p2++;
		}
		if (*p2 == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
