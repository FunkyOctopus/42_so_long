/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:22:07 by olgerret          #+#    #+#             */
/*   Updated: 2021/08/27 16:28:46 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_gnl_helper(char *temp, char *str, t_gnl *var)
{
	while (var->i < var->size)
	{
		temp[var->i] = str[var->i];
		var->i += 1;
	}
}

char	ft_get_next_line(int fd, char **line)
{
	t_gnl	var;

	var.character = ' ';
	var.size = 0;
	while (var.character != '\0')
	{
		var.amount_read = read(fd, &var.character, 1);
		if (var.amount_read == -1)
			exit(0);
		if (var.character == '\n' || var.amount_read == 0)
			var.character = '\0';
		var.temp = malloc((var.size + 1));
		if (var.temp == 0)
			return (-1);
		var.i = 0;
		ft_gnl_helper(var.temp, var.str, &var);
		var.size++;
		var.temp[var.i] = var.character;
		var.str = ft_strdup(var.temp);
		ft_single_free(&var.temp);
	}
	*line = var.str;
	if (var.amount_read == 0)
		return (0);
	return (1);
}
