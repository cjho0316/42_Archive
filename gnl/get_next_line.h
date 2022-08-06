/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 02:45:23 by jang-cho          #+#    #+#             */
/*   Updated: 2022/08/06 15:58:38 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE 1

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*afterline_word(char *p);
char	*ft_strdup1(const char *src);
char	*firstline_word(char *p);
char	*read_line(int fd, char *p);
void	ft_strlcpy1(char *dst, const char *src, size_t size);
char	*ft_strjoin1(char *s1, char *s2);
int		ft_strchr_idx(char *s, char c);
int		ft_strlen1(char *str);

#endif