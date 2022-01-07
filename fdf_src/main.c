/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:16:01 by rburri            #+#    #+#             */
/*   Updated: 2022/01/07 08:19:36 by rburri           ###   ########.fr       */
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

	if (ac != 2)
		send_err(USR_ERR);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		send_err(OPEN_ERR);
	map = map_init();
	if (read_map(fd, &pts_stack, map) != 0)
		send_err(MAP_ERR);
	fdf = fdf_init();
	// draw_line(fdf, s, f, 0xffffff);
	// draw_square(fdf, (HIGHT/2 - 50), (WIDTH/2 - 50), 100, COLOR_BRICK_RED);
	mlx_hook(fdf->win, 2, 0, key_hook, &fdf);
	mlx_mouse_hook(fdf->win, mouse_hook, &fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	
	mlx_loop(fdf->mlx);
	return  (0);
}