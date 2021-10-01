/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_fillers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:13:44 by olgerret          #+#    #+#             */
/*   Updated: 2021/08/27 15:29:48 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_character(t_so_long *var)
{
	int		x;
	int		y;
	char	*file;

	file = "./images/Mario.xpm";
	var->mario_image = mlx_xpm_file_to_image(var->mlx,
			file, &var->width, &var->height);
	y = 0;
	while (y < var->row)
	{
		x = 0;
		while (x < var->col)
		{
			if (var->array[y][x] == 'P')
				mlx_put_image_to_window(var->mlx, var->win,
					var->mario_image, (x * 32), (y * 32));
			x++;
		}
		y++;
	}
}

void	ft_collectibles(t_so_long *var)
{
	int		x;
	int		y;
	void	*image;
	char	*file;

	file = "./images/Itembox.xpm";
	image = mlx_xpm_file_to_image(var->mlx,
			file, &var->width, &var->height);
	y = 0;
	while (y < var->row)
	{
		x = 0;
		while (x < var->col)
		{
			if (var->array[y][x] == 'C')
				mlx_put_image_to_window(var->mlx, var->win,
					image, (x * 32), (y * 32));
			x++;
		}
		y++;
	}
}

void	ft_exit_pipe(t_so_long *var)
{
	int		x;
	int		y;
	void	*image;
	char	*file;

	file = "./images/Pipe.xpm";
	image = mlx_xpm_file_to_image(var->mlx,
			file, &var->width, &var->height);
	y = 0;
	while (y < var->row)
	{
		x = 0;
		while (x < var->col)
		{
			if (var->array[y][x] == 'E')
				mlx_put_image_to_window(var->mlx, var->win,
					image, (x * 32), (y * 32));
			x++;
		}
		y++;
	}
}

void	ft_walls(t_so_long *var)
{
	int		x;
	int		y;
	void	*image;
	char	*file;

	file = "./images/Block.xpm";
	image = mlx_xpm_file_to_image(var->mlx,
			file, &var->width, &var->height);
	y = 0;
	while (y < var->row)
	{
		x = 0;
		while (x < var->col)
		{
			if (var->array[y][x] == '1')
				mlx_put_image_to_window(var->mlx, var->win,
					image, (x * 32), (y * 32));
			x++;
		}
		y++;
	}
}
