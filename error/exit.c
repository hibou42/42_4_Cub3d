/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:56:40 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/11 13:32:45 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_maps(t_cube *cube)
{
	int		i;

	i = 0;
	while (cube->map.maps[i])
	{
		free(cube->map.maps[i]);
		i++;
	}
	free(cube->map.maps);
}

int	close_window(t_cube *cube)
{
	if (cube->map.maps != NULL)
		free_maps(cube);
	(void)cube;
	exit(1);
}
