/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:35:58 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/12 20:36:02 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;

	p = lst;
	if (lst == 0)
		return (0);
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
		del(lst);
	}
	return (p);
}
