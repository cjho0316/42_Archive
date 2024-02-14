/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 02:45:23 by jang-cho          #+#    #+#             */
/*   Updated: 2022/08/08 18:05:36 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*afterline_word(char *p);
char	*firstline_word(char *p);
char	*read_line(int fd, char *p);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strlcpy(char *dst, const char *src, size_t size);
int		is_newline(char *save);
size_t	ft_strlen(char *str);

#endif