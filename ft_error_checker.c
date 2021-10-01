/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:16:40 by olgerret          #+#    #+#             */
/*   Updated: 2021/08/28 12:31:22 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_wall_checker(t_so_long *var)
{
	int	i;

	i = 0;
	while (i < var->col)
	{
		if (var->array[0][i] != '1' || var->array[var->row - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < var->row)
	{
		if (var->array[i][0] != '1' || var->array[i][var->col - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_char_checker(char *one_dim)
{
	int	length;
	int	i;

	length = ft_strlen(one_dim);
	i = 0;
	while (i < length)
	{
		if (one_dim[i] != '0' && one_dim[i] != '1' && one_dim[i] != 'C'
			&& one_dim[i] != 'E' && one_dim[i] != 'P')
			return (1);
		i++;
	}
	return (0);
}

int	ft_char_counter(char *one_dim)
{
	t_char_counter	var;

	var.c = 0;
	var.e = 0;
	var.p = 0;
	var.i = 0;
	while (one_dim[var.i] != '\0')
	{
		if (one_dim[var.i] == 'C')
			var.c++;
		if (one_dim[var.i] == 'E')
			var.e++;
		if (one_dim[var.i] == 'P')
			var.p++;
		var.i++;
	}
	if (var.c < 1)
		return (1);
	if (var.e < 1)
		return (1);
	if (var.p != 1)
		return (1);
	return (0);
}

int	ft_error_checker(char *one_dim, t_so_long *var)
{
	if (var->row == var->col
		|| ft_strlen(one_dim) % var->row != 0
		|| ft_strlen(one_dim) % var->col != 0
		|| (int)ft_strlen(one_dim) / var->col != var->row
		|| (int)ft_strlen(one_dim) / var->row != var->col
		|| ft_wall_checker(var) == 1
		|| ft_char_checker(one_dim) == 1
		|| ft_char_counter(one_dim) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid map\n", 2);
		return (1);
	}
	return (0);
}

int	ft_dot_ber_checker(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Wrong input\n", 2);
		return (1);
	}
	else if (argv[1][ft_strlen(argv[1]) - 4] != '.'
		&& argv[1][ft_strlen(argv[1]) - 3] != 'b'
		&& argv[1][ft_strlen(argv[1]) - 2] != 'e'
		&& argv[1][ft_strlen(argv[1]) - 1] != 'r')
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Wrong input\n", 2);
		return (1);
	}
	return (0);
}
