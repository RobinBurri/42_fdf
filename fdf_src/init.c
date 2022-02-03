/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:55:56 by rburri            #+#    #+#             */
/*   Updated: 2022/02/03 09:12:08 by rburri           ###   ########.fr       */
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
	data->win = mlx_new_window(data->mlx, WIDTH, HIGHT, TITLE);
	if (!data->win)
		send_err(FDF_INIT_ERR);
	data->img = mlx_new_image(data->mlx, HIGHT, WIDTH);
	data->addr = mlx_get_data_addr(data->img, &data->bit_per_pixel, &data->line_length, &data->endian);
		
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
	map->z_max = INT_MAX;
	map->z_min = 0;
	map->z_range = 0;
	return (map);
}

t_camera	*camera_init(t_map *map)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
		send_err(ERR_CAMERA_INIT);
	camera->zoom = FT_MIN((WIDTH / map->width / 2), (HIGHT / map->height / 2));
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}