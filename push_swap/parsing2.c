/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 05:55:27 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/27 10:54:50 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	aligned_check(t_deque *q)
{
	int		i;
	int		total;
	t_Node	*p;

	i = 0;
	p = q->head;
	total = q->dqcnt - 1;
	while (i < total)
	{	
		if (p->data < p->next->data)
		{
			return (0);
		}
		p = p->next;
		i++;
	}
	return (1);
}