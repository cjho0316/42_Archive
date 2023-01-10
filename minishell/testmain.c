#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    (void)env;

    char **str;  // Declare a double pointer 'str'
    int n = 3;   // Number of strings
    
    // Allocate memory for 'str'
    str = (char **)malloc(n * sizeof(char *));
    
    // Allocate memory for each string and store them using 'str'
    str[0] = (char *)malloc(10 * sizeof(char));
    strcpy(str[0], "n");
    str[1] = (char *)malloc(10 * sizeof(char));
    strcpy(str[1], "yabal");
    str[2] = (char *)malloc(10 * sizeof(char));
    strcpy(str[2], "!!!");
    
    ft_pwd("");
    ft_cd(str, env);
    ft_pwd("");

    return 0;
}