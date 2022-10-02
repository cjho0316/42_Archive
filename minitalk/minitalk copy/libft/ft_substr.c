/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:18:05 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/15 03:53:02 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	num;
	size_t	lens;

	lens = ft_strlen(s);
	if (s == 0)
		return (0);
	if (start > lens)
		return (ft_strdup(""));
	if (lens < len)
		num = lens;
	else
		num = len;
	p = (char *)malloc(sizeof(char) * (num + 1));
	if (p == 0)
		return (0);
	ft_strlcpy(p, s + start, len + 1);
	return (p);
}
