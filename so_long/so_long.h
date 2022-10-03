/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:40:31 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/03 21:27:35 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_img
{
	void	*tile_issac;
	void	*tile_door;
	void	*tile;
	void	*tile_collectable;
	void	*tile_obstacles;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		wid;
	int		hei;
	char	*str_line;
	int		all_col;
	int		col_cnt;
	int		walk_cnt;
}	t_game;

void	ft_putstr_fd(char *s, int fd);

char	*get_next_line(int fd);
char	*afterline_word(char *p);
char	*firstline_word(char *p);
char	*read_line(int fd, char *p);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strlcpy(char *dst, const char *src, size_t size);
int		is_newline(char *save);
size_t	ft_strlen(char *str);

void	game_init(t_game *game, char *map);
int		key_press(int keycode, t_game *game);
void	read_map(char *filename, t_game *g);

void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
int		exit_game(t_game *game);

t_img	img_init(void *mlx);
void	img_put(t_game *game, int w, int h);
void	img_set(t_game *game);

char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strddup(char *src);
int		ft_strllcpy(char *dst, char *src, int len);
char	*ft_strjjoin(char *s1, char *s2);

#endif