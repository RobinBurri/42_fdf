/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:55:56 by rburri            #+#    #+#             */
/*   Updated: 2022/01/06 08:24:21 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_mlx	*fdf_init(void)
{
	t_mlx	*fdf;
	
	fdf = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	if (!fdf)
		send_err(FDF_INIT_ERR);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		send_err(FDF_INIT_ERR);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HIGHT, TITLE);
	if (!fdf->win)
		send_err(FDF_INIT_ERR);
	fdf->img = mlx_new_image(fdf->mlx, HIGHT, WIDTH);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bit_per_pixel, &fdf->line_length, &fdf->endian);
		
	return (fdf);
}

t_map	*map_init(void)
{
	t_map	*map;
	
	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!map)
		send_err(MAP_INIT_ERR);
	map->height = 0;
	map->width = 0;
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->z_max = INT_MAX;
	map->z_min = 0;
	map->z_range = 0;
	return (map);
}
