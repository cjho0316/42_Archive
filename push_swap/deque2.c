/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:11:45 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/24 23:00:28 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	dqchkfirst(t_deque *p)
{
	if (dqisempty(p))
	{
		p_error(1);
	}
	return (p->head->data);
}

int	dqchklast(t_deque *p)
{
	if (dqisempty(p))
	{
		p_error(1);
	}
	return (p->tail->data);
}
