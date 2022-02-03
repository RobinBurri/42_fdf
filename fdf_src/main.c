/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:16:01 by rburri            #+#    #+#             */
/*   Updated: 2022/02/03 09:59:04 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <fcntl.h>

int main(int ac, char *av[])
{
	int fd;
	t_mlx	*data;
	t_point *pts_stack;
	t_map *map;
	t_point a;
	t_point b;
	t_point c;
	t_point d;

	a.x = 50;
	a.y = 50;
	
	b.x = 50;
	b.y = 100;
	
	c.x = 100;
	c.y = 100;
	
	d.x = 100;
	d.y = 50;

	pts_stack = NULL;
	int errno = 0;
	if (ac != 2)
		send_err(USR_ERR);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		send_err(OPEN_ERR);
	map = map_init();
	data = fdf_init();
	if (read_map(fd, &pts_stack, map) != 0)
		send_err(MAP_ERR);
	stack_to_coords_array(&pts_stack, map);
	map->camera = camera_init(map); 
	// draw(map, data);
	draw_line(data, a, b);
	// draw_line(data, b, c);
	// draw_line(data, a, d);
	// draw_line(data, d, c);
	// draw_line(data, b, a);
	// draw_line(data, c, b);
	// draw_line(data, d, a);
	// draw_line(data, c, d);
	
	mlx_hook(data->win, 2, 0, key_hook, &data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	
	mlx_loop(data->mlx);
	ft_free_stack(pts_stack);
	free(data->mlx);
	return  (0);
}