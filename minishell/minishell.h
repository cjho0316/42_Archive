/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangchoi <jangchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:02:36 by siykim            #+#    #+#             */
/*   Updated: 2023/01/10 13:41:48 by jangchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


//library (libft)
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);

// void	get_interface();
void	ft_echo(char **cmd);
void	ft_export(char *str, ...);
void	ft_cd(char **cmd, char **env);
void 	ft_exit(char **cmd, ...);


int		ft_isdigit(int c);
void	ft_pwd(char *str);
void	get_env(char **env);
#endif