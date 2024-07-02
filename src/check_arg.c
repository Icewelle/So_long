/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 02:39:47 by cluby             #+#    #+#             */
/*   Updated: 2024/07/02 15:42:20 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check if the file is in the good format.
void	checkarg(char *filename)
{
	int	i;
	int	comma;

	i = ft_strlen(filename);
	comma = 0;
	while (i--)
	{
		if (filename[i] == '.')
		{
			comma = 1;
			if ((filename[i + 1] != 'b' || filename[i + 2] != 'e' || \
			filename[i + 3] != 'r'))
				errors(FILE_NAME, NULL);
		}
	}
	if (comma == 0)
		errors(FILE_NAME, NULL);
}
