/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:52:19 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/12 20:22:40 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*p1;
	char const	*p2;
	char const	*k;
	char		*t;
	size_t		num;

	if (*s1 == 0 || *set == 0)
		return (0);
	while (ft_strchr(set, *s1))
		s1++;
	p1 = s1;
	k = s1;
	while (!ft_strchr(set, *k))
		k++;
	p2 = k;
	num = ft_strlen(p1) - ft_strlen(p2) + 1;
	t = malloc(num);
	return ((char *)ft_strlcpy(t, p1, num));
}
