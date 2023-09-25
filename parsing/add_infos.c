/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/09/20 16:20:01 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	add_path1(t_cube *cube, int nb, char *str);
void	add_path2(t_cube *cube, int nb, char *str);
void	add_tab1(t_cube *cube, int nb, char *str);
void	add_tab2(t_cube *cube, int nb, char *str);

void	add_info(t_cube *cube, char *str)
{
	if(str[0] == 'N')
		add_path1(cube, 1, str);
	else if (str[0] == 'S')
		add_path1(cube, 2, str);
	else if (str[0] == 'W')
		add_path2(cube, 3, str);
	else if (str[0] == 'E')
		add_path2(cube, 4, str);
	else if (str[0] == 'F')
		add_tab1(cube, 1, str);
	else if (str[0] == 'C')
		add_tab2(cube, 2, str);
	else
	{
		ft_printf("Error : Une ligne fout le zbeul\n");
		close_window(cube);
	}
}

void	add_path1(t_cube *cube, int nb, char *str)
{
	int	stop;

	stop = 0;
	if (nb == 1)
	{
		if (cube->mlx.path_no == NULL)
			cube->mlx.path_no = ft_substr(str, 3, ft_strlen(str) - 4);
		else
			stop = 1;
	}
	if (nb == 2)
	{
		if (cube->mlx.path_so == NULL)
			cube->mlx.path_so = ft_substr(str, 3, ft_strlen(str) - 4);
		else
			stop = 1;
	}
	if (stop == 1)
	{
		ft_printf("Error : Path deja attribue\n");
		close_window(cube);
	}
}

void	add_path2(t_cube *cube, int nb, char *str)
{
	int	stop;

	stop = 0;
	if (nb == 3)
	{
		if (cube->mlx.path_we == NULL)
			cube->mlx.path_we = ft_substr(str, 3, ft_strlen(str) - 4);
		else
			stop = 1;
	}
	if (nb == 4)
	{
		if (cube->mlx.path_ea == NULL)
			cube->mlx.path_ea = ft_substr(str, 3, ft_strlen(str) - 4);
		else
			stop = 1;
	}
	if (stop == 1)
	{
		ft_printf("Error : Path deja attribue\n");
		close_window(cube);
	}
}

void	add_tab1(t_cube *cube, int nb, char *str)
{
	int		stop;
	char	*tmp;

	stop = 0;
	if (nb == 1)
	{
		if (cube->mlx.floor_color == NULL)
		{
			tmp = ft_substr(str, 2, ft_strlen(str) - 3);
			cube->mlx.floor_color = ft_split(tmp, ',');
		}
		else
			stop = 1;
	}
	if (tmp)
		free(tmp);
	if (stop == 1)
	{
		ft_printf("Error : Color deja attribue\n");
		close_window(cube);
	}
}

void	add_tab2(t_cube *cube, int nb, char *str)
{
	int		stop;
	char	*tmp;

	stop = 0;
	if (nb == 2)
	{
		if (cube->mlx.roof_color == NULL)
		{
			tmp = ft_substr(str, 2, ft_strlen(str) - 3);
			cube->mlx.roof_color = ft_split(tmp, ',');
		}
		else
			stop = 1;
	}
	if (tmp)
		free(tmp);
	if (stop == 1)
	{
		ft_printf("Error : Color deja attribue\n");
		close_window(cube);
	}
}
