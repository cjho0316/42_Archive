/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:20:43 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/16 19:56:26 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = 0;
	while (*s)
	{
		if (*s == (const char)c)
			p = s;
		s++;
	}
	if (*s == (char)c)
		p = s;
	return ((char *)p);
}
