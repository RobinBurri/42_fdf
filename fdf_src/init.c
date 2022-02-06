/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:55:56 by rburri            #+#    #+#             */
/*   Updated: 2022/02/06 18:11:59 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_mlx	*fdf_init(void)
{
	t_mlx	*data;

	data = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	if (!data)
		send_err(FDF_INIT_ERR);
	data->mlx = mlx_init();
	if (!data->mlx)
		send_err(FDF_INIT_ERR);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
	if (!data->win)
		send_err(FDF_INIT_ERR);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bit_per_pixel,
			&data->line_length, &data->endian);
	return (data);
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
	map->z_max = 0;
	map->z_min = 0;
	map->z_range = 0;
	return (map);
}
