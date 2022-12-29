/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 02:27:48 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/28 17:09:18 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	command(t_deque *p, t_deque *s, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 4) == 0)
		swap(p);
	else if (ft_strncmp(cmd, "sb\n", 4) == 0)
		swap(p);
	else if (ft_strncmp(cmd, "ss\n", 4) == 0)
		ss(p, s);
	if (ft_strncmp(cmd, "pa\n", 4) == 0)
		push(p, s);
	if (ft_strncmp(cmd, "pb\n", 4) == 0)
		push(p, s);
	if (ft_strncmp(cmd, "ra\n", 4) == 0)
		rotate(p);
	if (ft_strncmp(cmd, "rb\n", 4) == 0)
		rotate(s);
	if (ft_strncmp(cmd, "rr\n", 4) == 0)
		rr(p, s);
	if (ft_strncmp(cmd, "rra\n", 5) == 0)
		reverse_rotate(p);
	if (ft_strncmp(cmd, "rrb\n", 5) == 0)
		reverse_rotate(s);
	if (ft_strncmp(cmd, "rrr\n", 5) == 0)
		rrr(p, s);
}
