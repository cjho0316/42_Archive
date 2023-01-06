/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:02:24 by siykim            #+#    #+#             */
/*   Updated: 2023/01/06 17:27:03 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(void)
{
	printf("      ___           ___           ___           ___       ___ \n");
	printf("     /\\  \\         /\\__\\         /\\  \\         /\\__\\     /\\__\\\n");
	printf("    /::\\  \\       /:/  /        /::\\  \\       /:/  /    /:/  /\n");
	printf("   /:/\\ \\  \\     /:/__/        /:/\\:\\  \\     /:/  /    /:/  / \n");
	printf("  _\\:\\~\\ \\  \\   /::\\  \\ ___   /::\\~\\:\\  \\   /:/  /    /:/  /  \n");
	printf(" /\\ \\:\\ \\ \\__\\ /:/\\:\\  /\\__\\ /:/\\:\\ \\:\\__\\ /:/__/    /:/__/   \n");
	printf(" \\:\\ \\:\\ \\/__/ \\/__\\:\\/:/  / \\:\\~\\:\\ \\/__/ \\:\\  \\    \\:\\  \\   \n");
	printf("  \\:\\ \\:\\__\\        \\::/  /   \\:\\ \\:\\__\\    \\:\\  \\    \\:\\  \\  \n");
	printf("   \\:\\/:/  /        /:/  /     \\:\\ \\/__/     \\:\\  \\    \\:\\  \\ \n");
	printf("    \\::/  /        /:/  /       \\:\\__\\        \\:\\__\\    \\:\\__\\\n");
	printf("     \\/__/         \\/__/         \\/__/         \\/__/     \\/__/\n");
}

void	prompt(void)
{
	char	*str;

	init();
	while (1)
	{
		str = readline("shell$");
		if (!str)
			break ;
		printf("%s\n", str);
		add_history(str);
		free(str);
	}
}

int	main(int argc, char **argv, char **env)
{
	// char	*hwa;
	// char	*tmp;

	(void)argc;
	(void)argv;
	(void)env;
	//input interface implementation
	// get_env(env);
	get_export("general=sdfsdf");
	prompt();

	return (0);
}
