/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangchoi <jangchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:02:36 by siykim            #+#    #+#             */
/*   Updated: 2023/01/08 13:42:40 by jangchoi         ###   ########.fr       */
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

//library (libft)
// void	get_interface();

// builtin functions
void	ft_pwd(char *foo);
void	ft_echo(int foo, ...);
void	ft_cd(int foo, ...);
void	ft_env(char **env);
void	ft_export(char *foo, ...);
void	ft_unset(int foo, ...);
void	ft_exit(int foo, ...);

int     is_builtin(char *str);
void    interface(char *cmd);
#endif