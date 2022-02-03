/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:07:35 by rburri            #+#    #+#             */
/*   Updated: 2022/02/03 09:16:22 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
** Rotate coordinate by x axis
*/

static void	rotate_x(int *y, int *z, double alpha)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

/*
** Rotate coordinate by y axis
*/

static void	rotate_y(int *x, int *z, double beta)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

/*
** Rotate coordinate by z axis
*/

static void	rotate_z(int *x, int *y, double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

/*
** Convert coordinate to iso projection
*/

static void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

/*
** Project coordinate to 2D plane
*/

t_point		project(t_point p, t_map *map)
{
	p.x *= map->camera->zoom;
	p.y *= map->camera->zoom;
	p.z *= map->camera->zoom / map->camera->z_divisor;
	p.x -= (map->width * map->camera->zoom) / 2;
	p.y -= (map->height * map->camera->zoom) / 2;
	rotate_x(&p.y, &p.z, map->camera->alpha);
	rotate_y(&p.x, &p.z, map->camera->beta);
	rotate_z(&p.x, &p.y, map->camera->gamma);
	iso(&p.x, &p.y, p.z);
	p.x += (WIDTH / 2 + map->camera->x_offset);
	p.y += (HIGHT + map->height * map->camera->zoom) / 2
												+ map->camera->y_offset;
	return (p);
}
