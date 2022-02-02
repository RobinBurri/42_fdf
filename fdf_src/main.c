/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:16:01 by rburri            #+#    #+#             */
/*   Updated: 2022/01/12 09:36:28 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <fcntl.h>

int main(int ac, char *av[])
{
	int fd;
	t_mlx	*fdf;
	t_point *pts_stack;
	t_map *map;

	pts_stack = NULL;
	int errno = 0;
	if (ac != 2)
		send_err(USR_ERR);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		send_err(OPEN_ERR);
	map = map_init();
	fdf = fdf_init();
	if (read_map(fd, &pts_stack, map) != 0)
		send_err(MAP_ERR);
	// ft_print_stack(pts_stack);
	printf("height: %d\n", map->height);
	printf("width: %d\n", map->width);
	stack_to_coords_array(&pts_stack, map);
	map->camera = camera_init(map);
	printf("%d\n", map->camera->zoom);
	draw(map, fdf);
	// draw_line(fdf, s, f);
	// draw_square(fdf, (HIGHT/2 - 50), (WIDTH/2 - 50), 100, COLOR_BRICK_RED);
	// mlx_hook(fdf->win, 2, 0, key_hook, &fdf);
	// mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	
	mlx_loop(fdf->mlx);
	ft_free_stack(pts_stack);
	return  (0);
}