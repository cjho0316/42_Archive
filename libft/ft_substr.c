/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:18:05 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/13 08:15:49 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == 0 || len < 0)
		return (0);
	ft_strlcpy(p, s + start, len + 1);
	return (p);
}
