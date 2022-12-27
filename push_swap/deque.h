/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:11:45 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/26 18:56:57 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define INT_MAX 2147483647
# include <unistd.h>
# include <stdlib.h>

typedef struct s_Node{
	int				data;
	struct s_Node	*prev;
	struct s_Node	*next;
}	t_Node;

typedef struct s_deque{
	int		dqcnt;
	t_Node	*head;
	t_Node	*tail;
}	t_deque;

//libft (library1, 2)
void		ft_putstr_fd(char *s, int fd);
int			ft_strlen(const char *str);
int			put_idx(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(const char *str);

char		**ft_split(char const *s, char c);
long long	ft_atoll(const char *str);

//deque1

int			dqisempty(t_deque *p);
void		dqaddfirst(t_deque *p, int data);
void		dqaddlast(t_deque *p, int data);
int			dqpopfirst(t_deque *p);
int			dqpoplast(t_deque *p);

//deque2
void		dequeinit(t_deque *p);
int			dqchkfirst(t_deque *p);
int			dqchklast(t_deque *p);

//instruction1,2,3
void		swap(t_deque *p);
void		push(t_deque *from, t_deque *to);
void		rotate(t_deque *p);
void		reverse_rotate(t_deque *p);

void		ss(t_deque *p, t_deque *s);
void		rr(t_deque *p, t_deque *s);
void		rrr(t_deque *p, t_deque *s);
void		p_error(int i);

void		pa(t_deque *b, t_deque *a);
void		pb(t_deque *a, t_deque *b);
void		sa(t_deque *p);
void		sb(t_deque *p);

void		ra(t_deque *p);
void		rb(t_deque *p);
void		rra(t_deque *p);
void		rrb(t_deque *p);

//parsing1, 2
int			find_duplicate(t_deque *p, int num);
int			integrity_check(char *av);
int			arg2list(char *av, t_deque *dq);
int			argument_check(char *av);
void		push_in_deque(int ac, char **av, t_deque *dq);

int			aligned_check(t_deque *q);

//algorithmn1, 2
void		sorting_deque(t_deque *deq1, t_deque *deq2);
void		under_five(t_deque *a, t_deque *b);
void		over_five(t_deque *a, t_deque *b);
void		atob(t_deque *a, t_deque *b, int chunk, int i);
void		btoa(t_deque *a, t_deque *b);

void		drop_and_make(t_deque *a, int total, int *tmp);
void		indexing_all(t_deque *a);
int			get_mid_result(t_deque *a);
void		sort_two_three(t_deque *p);
void		sort_b(t_deque *b, int length);

//cmd
void		command(t_deque *p, t_deque *s, char *cmd);

//tmp
int			find_all(t_deque *dq);

#endif