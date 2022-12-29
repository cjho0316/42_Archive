/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:47:19 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/29 17:52:08 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdio.h>

void	cmd_bonus(t_deque *a, t_deque *b, char *cmd)
{
	if (ft_strncmp(cmd, "sa", 2) == 0)
		bonus_sa(a);
	else if (ft_strncmp(cmd, "sb", 2) == 0)
		bonus_sb(b);
	else if (ft_strncmp(cmd, "ss", 2) == 0)
		bonus_ss(a, b);
	else if (ft_strncmp(cmd, "pa", 2) == 0)
		bonus_pa(a, b);
	else if (ft_strncmp(cmd, "pb", 2) == 0)
		bonus_pb(a, b);
	else if (ft_strncmp(cmd, "ra", 2) == 0)
		bonus_ra(a);
	else if (ft_strncmp(cmd, "rb", 2) == 0)
		bonus_rb(b);
	else if (ft_strncmp(cmd, "rra", 3) == 0)
		bonus_rra(a);
	else if (ft_strncmp(cmd, "rrb", 3) == 0)
		bonus_rrb(b);
	else if (ft_strncmp(cmd, "rrr", 3) == 0)
		bonus_rrr(a, b);
	else if (ft_strncmp(cmd, "rr", 2) == 0)
		bonus_rr(a, b);
	else
		p_error(1);
}

void	check_cmd(t_deque *a, t_deque *b)
{
	char	*cmd;

	cmd = get_cmd(0);
	while (cmd)
	{
		cmd_bonus(a, b, cmd);
		free(cmd);
		cmd = 0;
		cmd = get_cmd(0);
	}
	free(cmd);
	cmd = 0;
}

char	*get_cmd(int fd)
{
	char	*cmd;
	char	*result;

	cmd = get_next_line(fd);
	result = ft_strtrim(cmd, "\n");
	free(cmd);
	cmd = 0;
	return (result);
}

void	print_result(t_deque *a, t_deque *b)
{
	int i = 0;
	t_Node *p;
	p = a->head;
	//printf("%d", b->dqcnt);
	while(i < a->dqcnt)
	{
		printf("%d", p->data);
		p = p->next;
		i++;
	}

	// printf("%d", aligned_check(a));
	if (b->dqcnt == 0 && aligned_check(a))
	{
		ft_putstr_fd("OK\n", 1);	
		free(a);
		free(b);
		exit(1);
	}
	else
	{
		ft_putstr_fd("KO\n", 1);
		free(a);
		free(b);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_deque	*a;
	t_deque	*b;

	a = malloc(sizeof(t_deque));
	b = malloc(sizeof(t_deque));
	dequeinit(a);
	dequeinit(b);
	push_in_deque(ac, av, a);
	chk_avvalsorted(a);
	check_cmd(a, b);
	print_result(a, b);

	return (0);
}
