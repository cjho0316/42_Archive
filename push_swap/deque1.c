/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:11:45 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/29 09:23:30 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	dqisempty(t_deque *p)
{
	if (p->head == NULL)
		return (1);
	else
		return (0);
}

void	dqaddfirst(t_deque *p, int data)
{
	t_Node	*newnode;

	newnode = (t_Node *)malloc(sizeof(t_Node));
	newnode->data = data;
	if (dqisempty(p))
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		p->head = newnode;
		p->tail = newnode;
	}
	else
	{
		newnode->next = p->head;
		newnode->prev = NULL;
		p->head->prev = newnode;
		p->head = newnode;
	}
	p->dqcnt++;
}

void	dqaddlast(t_deque *p, int data)
{
	t_Node	*newnode;

	newnode = (t_Node *)malloc(sizeof(t_Node));
	newnode->data = data;
	if (dqisempty(p))
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		p->head = newnode;
		p->tail = newnode;
	}
	else
	{
		newnode->next = NULL;
		newnode->prev = p->tail;
		p->tail->next = newnode;
		p->tail = newnode;
	}
	p->dqcnt++;
}

int	dqpopfirst(t_deque *p)
{
	t_Node	*del;
	int		pop;

	if (dqisempty(p))
	{
		p_error(1);
	}
	pop = p->head->data;
	del = p->head;
	p->head = p->head->next;
	free(del);
	if (p->head == NULL)
		p->tail = NULL;
	else
	{
		p->head->prev = NULL;
	}
	p->dqcnt--;
	return (pop);
}

int	dqpoplast(t_deque *p)
{
	t_Node	*del;
	int		pop;

	if (dqisempty(p))
	{
		p_error(1);
	}
	pop = p->tail->data;
	del = p->tail;
	p->tail = p->tail->prev;
	free(del);
	if (p->tail == NULL)
		p->head = NULL;
	else
	{
		p->tail->next = NULL;
	}
	p->dqcnt--;
	return (pop);
}
