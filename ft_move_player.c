/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:09:48 by olgerret          #+#    #+#             */
/*   Updated: 2021/08/27 14:12:15 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_player_position(t_move *m_var, t_so_long *var)
{
	int			x;
	int			y;

	y = 0;
	while (y < var->row)
	{
		x = 0;
		while (x < var->col)
		{
			if (var->array[y][x] == 'P')
			{
				m_var->x_p = x;
				m_var->y_p = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_amount_collectibles(t_so_long *var)
{
	int	x;
	int	y;
	int	c;

	y = 0;
	c = 0;
	while (y < var->row)
	{
		x = 0;
		while (x < var->col)
		{
			if (var->array[y][x] == 'C')
			{
				c += 1;
				var->collectibles = c;
			}
			x++;
		}
		y++;
	}
}

void	ft_move_du(t_move *m_var, t_so_long *var, char DU)
{
	if (DU == 'U')
		m_var->y = -1;
	if (DU == 'D')
		m_var->y = 1;
	if ((var->array[m_var->y_p + m_var->y][m_var->x_p + m_var->x] == 'E'
		&& var->collectibles == 0))
		ft_you_win();
	if (var->array[m_var->y_p + m_var->y][m_var->x_p + m_var->x] == '0'
		|| var->array[m_var->y_p + m_var->y][m_var->x_p + m_var->x] == 'C')
	{
		if (var->array[m_var->y_p + m_var->y][m_var->x_p + m_var->x] == 'C')
		{
			var->collectibles -= 1;
			mlx_put_image_to_window(var->mlx, var->win, var->zero_image,
				(m_var->x_p + m_var->x) * 32, (m_var->y_p + m_var->y) * 32);
		}
		mlx_put_image_to_window(var->mlx, var->win,
			var->zero_image, m_var->x_p * 32, m_var->y_p * 32);
		mlx_put_image_to_window(var->mlx, var->win, var->mario_image,
			(m_var->x_p + m_var->x) * 32, (m_var->y_p + m_var->y) * 32);
		var->array[m_var->y_p][m_var->x_p] = '0';
		var->array[m_var->y_p + m_var->y]
		[m_var->x_p + m_var->x] = 'P';
		printf("%d\n", (var->move_counter += 1));
	}
}

void	ft_move_lr(t_move *m_var, t_so_long *var, char LR)
{
	if (LR == 'L')
		m_var->x = -1;
	if (LR == 'R')
		m_var->x = 1;
	if ((var->array[m_var->y_p + m_var->y][m_var->x_p + m_var->x] == 'E'
		&& var->collectibles == 0))
		ft_you_win();
	if (var->array[m_var->y_p + m_var->y][m_var->x_p + m_var->x] == '0'
		|| var->array[m_var->y_p + m_var->y][m_var->x_p + m_var->x] == 'C')
	{
		if (var->array[m_var->y_p + m_var->y][m_var->x_p + m_var->x] == 'C')
		{
			var->collectibles -= 1;
			mlx_put_image_to_window(var->mlx, var->win, var->zero_image,
				(m_var->x_p + m_var->x) * 32, (m_var->y_p + m_var->y) * 32);
		}
		mlx_put_image_to_window(var->mlx, var->win, var->zero_image,
			m_var->x_p * 32, m_var->y_p * 32);
		mlx_put_image_to_window(var->mlx, var->win, var->mario_image,
			(m_var->x_p + m_var->x) * 32, (m_var->y_p + m_var->y) * 32);
		var->array[m_var->y_p][m_var->x_p] = '0';
		var->array[m_var->y_p + m_var->y]
		[m_var->x_p + m_var->x] = 'P';
		printf("%d\n", (var->move_counter += 1));
	}
}

int	ft_wasd_sender(int keycode, t_so_long *var)
{
	t_move	m_var;

	m_var.x = 0;
	m_var.y = 0;
	ft_amount_collectibles(var);
	ft_player_position(&m_var, var);
	if (keycode == 0 || keycode == 123)
		ft_move_lr(&m_var, var, 'L');
	if (keycode == 2 || keycode == 124)
		ft_move_lr(&m_var, var, 'R');
	if (keycode == 1 || keycode == 125)
		ft_move_du(&m_var, var, 'D');
	if (keycode == 13 || keycode == 126)
		ft_move_du(&m_var, var, 'U');
	if (keycode == 53)
		exit(0);
	return (0);
}
