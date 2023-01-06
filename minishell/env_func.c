/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:00:13 by jang-cho          #+#    #+#             */
/*   Updated: 2023/01/06 17:27:01 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//데이터 어케관리할지 고민
void	get_env(char **env)
{
	while (*env)
		printf("%s\n", *env++);
}

// 1. 이미 존재하는 환경변수면 free -> dup
// 2. 인자 하나면 환경변수 저장 x
// 3. 새로운 환경변수면 (원래크기 + 2) 짜리 **new 생성
//  1) 기존 환경변수 dup 해주고
//  2) 새 환경변수 NULL 추가
// 4. 기존 환경변수 free후 **new로 대체
// 5. 파이프 뒤에 있으면 자식프로세스의 export이기에 환경변수 생성 x
void	ft_export(char *str, ...)
{
	int		i;
	char	*key;
	char	*val;
	char	**tmp;

	i = -1;
	key = NULL;
	val = NULL;
	tmp = ft_split(str, ' ');
	while (tmp[++i])
	{
		key = tmp[i];
		if (tmp[i][0] == '=' || ft_isdigit(tmp[i][0]))
		{
			printf("%s: not a valid identifier\n", tmp[i]);
			exit(1);
		}
		while (*str)
		{
			if (*str == '=')
				break ;
			str++;
		}
		str ++;
		val = str;
		// printf("%s\n", key);
		// printf("%s\n", val);
	}
}

void	get_unset(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			printf("bash: unset: '%s': not a valid identifier", str);
			exit(1);
		}
		i++;
	}
}
