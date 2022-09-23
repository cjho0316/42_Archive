/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:53:57 by jang-cho          #+#    #+#             */
/*   Updated: 2022/09/23 17:11:20 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

void	atob(int pid, char *str, int len);
void	send_sig(int pid, char *av);
void	get_sig(int sig);
void	ft_putchar(char c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr(char *str);
int		put_idx(const char *str);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	int2char(int nb);
void	ft_putnbr(int nb);

#endif