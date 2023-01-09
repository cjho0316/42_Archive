/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:00:13 by jang-cho          #+#    #+#             */
/*   Updated: 2023/01/09 14:58:07 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **env)
{
	while (*env)
		printf("%s\n", *env++);
}

// get_env as strnstr?
// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	const char	*p1;
// 	const char	*p2;

// 	if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0 || *needle == 0)
// 		return ((char *)haystack);
// 	if (*haystack == 0 || len == 0)
// 		return (0);
// 	while (*haystack++ != '\0' && len--)
// 	{
// 		p1 = haystack;
// 		p2 = needle;
// 		while (*p1 != '\0' && *p2 != '\0' && (*p1 == *p2))
// 		{
// 			if ((haystack + len) == p1)
// 				return (0);
// 			p1++;
// 			p2++;
// 		}
// 		if (*p2 == '\0')
// 			return ((char *)haystack);
// 	}
// 	return (0);
// }