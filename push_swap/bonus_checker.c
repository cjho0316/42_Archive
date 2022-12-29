/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:47:19 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/29 13:33:44 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	cmd_bonus(t_deque *a, t_deque *b, char *cmd)
{
	if (ft_strncmp(cmd, "sa", 2) == 0)
		sa(a);
	else if (ft_strncmp(cmd, "sb", 2) == 0)
		sb(b);
	else if (ft_strncmp(cmd, "ss", 2) == 0)
		ss(a, b);
	else if (ft_strncmp(cmd, "pa", 2) == 0)
		pa(a, b);
	else if (ft_strncmp(cmd, "pb", 2) == 0)
		pb(a, b);
	else if (ft_strncmp(cmd, "ra", 2) == 0)
		ra(a);
	else if (ft_strncmp(cmd, "rb", 2) == 0)
		rb(b);
	else if (ft_strncmp(cmd, "rr", 2) == 0)
		rr(a, b);
	else if (ft_strncmp(cmd, "rra", 3) == 0)
		rra(a);
	else if (ft_strncmp(cmd, "rrb", 3) == 0)
		rrb(b);
	else if (ft_strncmp(cmd, "rrr", 3) == 0)
		rrr(a, b);
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
	char	*command;
	char	*result;

	command = get_next_line(fd);
	result = ft_strtrim(command, "\n");
	free(command);
	command = 0;
	return (result);
}

void	print_result(t_deque *a, t_deque *b)
{
	if (b->dqcnt == 0 && check_input(a))
	{
		ft_putstr_fd("OK\n", 1);
		exit(1);
	}
	else
	{
		ft_putstr_fd("KO\n", 1);
		exit(0);
	}
}

int	main(int ac, char *av)
{
	t_deque	*a;
	t_deque	*b;

	a = malloc(sizeof(t_deque));
	b = malloc(sizeof(t_deque));
	dequeinit(a);
	dequeinit(b);
	if (ac < 2)
		exit (1);
	push_in_deque(ac, av, a);
	chk_avvalsorted(a);
	check_cmd(a, b);
	print_result(a, b);
	free(a);
	free(b);
	return (0);
}
