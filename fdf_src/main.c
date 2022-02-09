/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:16:01 by rburri            #+#    #+#             */
/*   Updated: 2022/02/09 17:23:15 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <fcntl.h>

int	main(int ac, char *av[])
{
	t_mlx	data;
	t_map	map;
	t_point	*stack;
	int		fd;

	if (ac != 2)
		send_err(USR_ERR);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		send_err(OPEN_ERR);
	fdf_init(&data);
	map_init(&map);
	if (read_map(fd, &stack, &map) == -1)
		send_err(MAP_ERR);
	stack_to_coords_array(&stack, &map);
	draw(&data, &map);
	free(map.coords_arr);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_loop(&data.mlx);
	return (0);
}
