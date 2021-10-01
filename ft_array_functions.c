/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:33:07 by olgerret          #+#    #+#             */
/*   Updated: 2021/08/28 12:37:06 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

char	**ft_one_to_two_dim(char *one_dim, t_so_long *var)
{
	int		i;
	int		j;
	int		k;
	char	**array;

	array = (char **)malloc((var->row + 1) * sizeof(char *));
	i = 0;
	k = 0;
	while (i < var->row)
	{
		j = 0;
		array[i] = (char *)malloc(var->col + 1 * sizeof(char));
		while (j < var->col)
		{
			array[i][j] = one_dim[k];
			k++;
			j++;
		}
		array[i][j] = '\0';
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	*ft_input_to_one_dim(char **argv, t_so_long *var)
{
	char	*str[50000];
	char	*temp;
	char	*one_dim;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	one_dim = ft_strdup("");
	while (ft_get_next_line(fd, str) != 0)
	{
		temp = one_dim;
		one_dim = ft_strjoin(temp, str[0]);
		ft_single_free(&temp);
		ft_single_free(&str[0]);
		var->row += 1;
	}
	temp = one_dim;
	one_dim = ft_strjoin(temp, str[0]);
	ft_single_free(&temp);
	ft_single_free(&str[0]);
	var->row += 1;
	close (fd);
	return (one_dim);
}
