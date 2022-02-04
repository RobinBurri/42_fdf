/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:07:35 by rburri            #+#    #+#             */
/*   Updated: 2022/02/04 10:35:05 by rburri           ###   ########.fr       */
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

	zoom = FT_MIN((WIDTH / map->width / 2), (HIGHT / map->height / 2));
	p.x *= zoom;
	p.y *= zoom;
	if (map->z_range <= zoom)
		p.z *= zoom;
	else
		p.z *= (HIGHT / map->z_range / 2);
	iso(&p.x, &p.y, p.z);
	p.x += (WIDTH / 2) - (zoom * map->width / 2) + (map->height * zoom / 2);
	p.y += (HIGHT / 2) - (zoom * map->height / 2);
	return (p);
}
