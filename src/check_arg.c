/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 02:39:47 by cluby             #+#    #+#             */
/*   Updated: 2024/07/01 13:16:19 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check if the file is in the good format.
void	checkarg(char *filename)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
		{
			comma = 1;
			if ((filename[i + 1] != 'b' || filename[i + 2] != 'e' || \
			filename[i + 3] != 'r'))
				errors(FILE_NAME, NULL);
		}
		i++;
	}
	if (comma == 0)
		errors(FILE_NAME, NULL);
}
