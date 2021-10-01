/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:33:07 by olgerret          #+#    #+#             */
/*   Updated: 2021/08/27 15:58:42 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_single_free(char **string)
{
	if (!string)
		return ;
	free(*string);
	*string = 0;
}

void	ft_double_free(char	**string)
{
	int	i;

	i = 0;
	if (!string)
		return ;
	while (string[i] != NULL)
	{
		ft_single_free(&string[i]);
		i++;
	}
	free(string);
	string = 0;
}

void	ft_you_win(void)
{
	ft_putstr_fd("Good job!\n", 1);
	exit(0);
}

int	ft_close_game(void)
{
	exit(0);
}
