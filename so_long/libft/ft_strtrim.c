/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:52:19 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/17 00:32:57 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*p1;
	char const	*p2;
	char		*t;
	size_t		i;

	i = 0;
	if (s1 == 0 || set == 0)
		return (0);
	p1 = s1;
	p2 = s1 + ft_strlen(s1);
	while (*p1 != '\0' && ft_strrchr(set, *p1))
	{
		if (p1++ >= p2)
			return (ft_strdup(""));
	}
	while (ft_strrchr(set, *p2))
	{
		if (p1 >= p2--)
			return (ft_strdup(""));
	}
	t = (char *)malloc(sizeof(char) * (ft_strlen(p1) - ft_strlen(p2) + 2));
	if (t == 0)
		return (0);
	ft_strlcpy(t, p1, (ft_strlen(p1) - ft_strlen(p2) + 2));
	return (t);
}
