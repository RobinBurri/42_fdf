/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:07:35 by rburri            #+#    #+#             */
/*   Updated: 2022/02/07 11:28:42 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	iso(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

t_point	project(t_point p, t_map *map)
{
	int	zoom;
	int	tmp;

	if ((WIDTH / map->width / 2) < (HEIGHT / map->height / 2))
		tmp = (WIDTH / map->width / 2);
	else
		tmp = (HEIGHT / map->height / 2);
	if (map->z_range > 0 && (HEIGHT / map->z_range / 2) < tmp)
		zoom = (HEIGHT / map->z_range / 2);
	else
		zoom = tmp;
	p.x *= zoom;
	p.y *= zoom;
	p.z *= zoom;
	iso(&p.x, &p.y, p.z);
	p.x += (WIDTH / 2) - (zoom * map->width / 2) + (map->height * zoom / 2);
	if (map->z_range > 0 && (HEIGHT / map->z_range / 2) > zoom)
		p.y += (HEIGHT / 2) - (zoom * map->height / 2);
	else
		p.y += (HEIGHT / 2) - (zoom * map->z_range / 20);
	return (p);
}
