/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:11:45 by jang-cho          #+#    #+#             */
/*   Updated: 2022/11/25 23:57:50 by jang-cho         ###   ########.fr       */
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

//libft (library1,2)
int			ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(const char *str);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
long long	ft_atoll(const char *str);

//deque
void		dequeinit(t_deque *p);
int			dqisempty(t_deque *p);
void		dqaddfirst(t_deque *p, int data);
void		dqaddlast(t_deque *p, int data);
int			dqpopfirst(t_deque *p);
int			dqpoplast(t_deque *p);

//instruction1,2
void		swap(t_deque *p);
void		push(t_deque *from, t_deque *to);
void		rotate(t_deque *p);
void		reverse_rotate(t_deque *p);

void		ss(t_deque *p, t_deque *s);
void		rr(t_deque *p, t_deque *s);
void		rrr(t_deque *p, t_deque *s);
void		p_error(int i);

//parsing1
int			integrity_check(char *av, int num);
int			arg2list(char *av, t_deque *dq);
int			argument_check(char *av);
void		push_in_deque(int ac, char **av, t_deque *dq);
int			find_duplicate(t_deque *p, int num);

//cmd
void		command(t_deque *p, t_deque *s, char *cmd);

#endif