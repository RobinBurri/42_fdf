/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:16:01 by rburri            #+#    #+#             */
/*   Updated: 2022/02/04 11:14:26 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <fcntl.h>

int	main(int ac, char *av[])
{
	t_point	*pts_stack;
	t_mlx	*data;
	t_map	*map;
	int		fd;

	pts_stack = NULL;
	if (ac != 2)
		send_err(USR_ERR);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		send_err(OPEN_ERR);
	data = fdf_init();
	data->map = map_init();
	if (read_map(fd, &pts_stack, data->map) == -1)
		send_err(MAP_ERR);
	stack_to_coords_array(&pts_stack, data->map);
	draw(data);
	mlx_hook(data->win, 2, 0, key_hook, &data);
	mlx_loop(data->mlx);
	ft_free_stack(pts_stack);
	free(data->mlx);
	ft_free_map(data->map);
	return (0);
}
