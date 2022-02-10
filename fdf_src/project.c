/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:07:35 by rburri            #+#    #+#             */
/*   Updated: 2022/02/10 09:23:04 by rburri           ###   ########.fr       */
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
		zoom = (HEIGHT / map->z_range / 1.1);
	else
		zoom = tmp;
	p.x *= zoom;
	p.y *= zoom;
	p.z *= zoom;
	if (map->z_range >= 20)
		p.z /= 2;
	if (map->z_range / map->width > 3)
	{
		p.x *= 2;
		p.y *= 2;
	}
	iso(&p.x, &p.y, p.z);
	p.x += (WIDTH / 2) - (zoom * map->width / 2) + (map->height * zoom / 2);
	p.y += (HEIGHT / 2) - (zoom * map->height / 4);
	return (p);
}
