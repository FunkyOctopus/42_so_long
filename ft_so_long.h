/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 07:38:52 by olgerret          #+#    #+#             */
/*   Updated: 2021/08/27 15:29:48 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdio.h>

typedef struct s_so_long
{
	void	*mlx;
	void	*win;

	int		width;
	int		height;

	int		col;
	int		row;

	void	*mario_image;
	void	*zero_image;

	char	**array;
	int		move_counter;
	int		collectibles;
}			t_so_long;

typedef struct s_move
{
	int		x_p;
	int		y_p;

	int		x;
	int		y;
}			t_move;

typedef struct s_char_counter
{
	int	i;

	int	c;
	int	e;
	int	p;
	int	zero;
}			t_char_counter;

typedef struct s_gnl
{
	int		amount_read;
	int		i;
	int		size;

	char	character;
	char	*str;
	char	*temp;
}			t_gnl;

int		main(int argc, char **argv);

char	ft_get_next_line(int fd, char **line);

char	*ft_input_to_one_dim(char **argv, t_so_long *var);
char	**ft_one_to_two_dim(char *one_dim, t_so_long *var);

int		ft_dot_ber_checker(int argc, char **argv);
int		ft_error_checker(char *one_dim, t_so_long *var);
int		ft_char_counter(char *one_dim);
int		ft_char_checker(char *one_dim);
int		ft_wall_checker(t_so_long *var);

void	ft_window_creator(t_so_long *var);
void	ft_background(t_so_long *var);

void	ft_character(t_so_long *var);
void	ft_collectibles(t_so_long *var);
void	ft_exit_pipe(t_so_long *var);
void	ft_walls(t_so_long *var);

int		ft_wasd_sender(int keycode, t_so_long *var);
void	ft_move_lr(t_move *m_var, t_so_long *var, char LR);
void	ft_move_du(t_move *m_var, t_so_long *var, char DU);
void	ft_amount_collectibles(t_so_long *var);
void	ft_player_position(t_move *m_var, t_so_long *var);

int		ft_close_game(void);
void	ft_you_win(void);
void	ft_double_free(char	**string);
void	ft_single_free(char **string);

#endif
