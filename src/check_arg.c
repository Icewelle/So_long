/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 02:39:47 by cluby             #+#    #+#             */
/*   Updated: 2024/06/09 02:58:11 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
			if ((filename[i + 1] != 'b' || filename[i + 2] != 'e' || filename[i + 3] != 'r'))
				errors(FILE_NAME, NULL);
		}
		i++;
	}
	if (comma == 0)
		errors(FILE_NAME, NULL);
}
