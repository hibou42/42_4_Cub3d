/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/13 15:05:11 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_cube *cube)
{
	t_mlx	mlx;
	t_map	map;

	mlx = (t_mlx){};
	map = (t_map){};
	cube->mlx = mlx;
	cube->map = map;
	cube->map.maps = NULL;

}

int	main(int argc, char **argv)
{
	t_cube	cube;

	cube = (t_cube){};
	init_struct(&cube);
	check_arg(argc, argv);
	parsing(&cube, argv);
	check_parsing(&cube);
	cube.mlx.mlx_ptr = mlx_init();
	cube.mlx.mlx_win = mlx_new_window(cube.mlx.mlx_ptr, 1920, 1080, "Cub3d");
	//init_img(&cube);
	mlx_key_hook(cube.mlx.mlx_win, game, &cube);
	mlx_hook(cube.mlx.mlx_win, 17, 1L << 0, close_window, &cube);
	mlx_loop(cube.mlx.mlx_ptr);
	close_window(&cube);
	return (0);
}

/*
Setup if mouse is needed :

mlx_mouse_hook(map.mlx_win, deal_mouse, (void*)0);
int	deal_mouse(int key)
{
	(void) key;
	return (0);
}
*/