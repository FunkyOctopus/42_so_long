/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 09:36:33 by olgerret          #+#    #+#             */
/*   Updated: 2021/08/28 12:40:47 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_background(t_so_long *var)
{
	int		x;
	int		y;
	char	*file;

	file = "./images/Background.xpm";
	var->zero_image = mlx_xpm_file_to_image(var->mlx,
			file, &var->width, &var->height);
	y = 0;
	while (y < var->row)
	{
		x = 0;
		while (x < var->col)
		{
			mlx_put_image_to_window(var->mlx, var->win,
				var->zero_image, (x * 32), (y * 32));
			x++;
		}
		y++;
	}
}

void	ft_window_creator(t_so_long *var)
{
	ft_background(var);
	ft_walls(var);
	ft_collectibles(var);
	ft_exit_pipe(var);
	ft_character(var);
}

int	main(int argc, char **argv)
{
	t_so_long	var;
	char		*one_dim;

	if (ft_dot_ber_checker(argc, argv) == 1)
		exit (0);
	var.row = 0;
	one_dim = ft_input_to_one_dim(argv, &var);
	var.col = ft_strlen(one_dim) / var.row;
	var.array = ft_one_to_two_dim(one_dim, &var);
	if (ft_error_checker(one_dim, &var) == 1)
		exit (0);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, (var.col * 32), (var.row * 32), "Mario");
	ft_window_creator(&var);
	mlx_key_hook(var.win, ft_wasd_sender, &var);
	mlx_hook(var.win, 17, (1L << 17), ft_close_game, &var);
	mlx_loop(var.mlx);
	return (0);
}
