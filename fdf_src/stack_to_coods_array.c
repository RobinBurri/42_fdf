/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_coods_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:16:19 by rburri            #+#    #+#             */
/*   Updated: 2022/02/04 08:31:12 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	stack_to_coords_array(t_point **pts_stack, t_map *map)
{
	size_t	arr_size;
	size_t	i;
	t_point	*tmp;

	arr_size = map->height * map->width * sizeof(int);
	i = map->width * map->height - 1;
	map->coords_arr = (int *)ft_memalloc(arr_size);
	if (!map->coords_arr)
		send_err(CONVERT_ARRAY_ERR);
	while ((tmp = pop_pts(pts_stack)) && i >= 0)
	{
		map->coords_arr[i] = tmp->z;
		if (tmp->z > map->z_max)
			map->z_max = tmp->z;
		if (tmp->z < map->z_min)
			map->z_min = tmp->z;
		i--;
		free(tmp);
	}
	map->z_range = map->z_max - map->z_min;
}
