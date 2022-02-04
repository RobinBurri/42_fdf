/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 08:19:53 by rburri            #+#    #+#             */
/*   Updated: 2022/02/04 09:36:39 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

t_point	new_point(int x, int y, t_map *map)
{
	t_point	point;
	int		index;

	index = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->coords_arr[index];
	return (point);
}

void	my_pixel_put(t_mlx *fdf, int x, int y, int color)
{
	char	*pixel;

	pixel = fdf->addr + (y * fdf->line_length + x * (fdf->bit_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	draw_line(t_mlx *fdf, t_point p1, t_point p2)
{
	t_point	delta;
	t_point	sign;
	int		err;
	int		e2;

	delta.x = abs(p2.x - p1.x);
	delta.y = abs(p2.y - p1.y);
	sign.x = p1.x < p2.x ? 1 : -1;
	sign.y = p1.y < p2.y ? 1 : -1;
	err = (delta.x > delta.y ? delta.x : -delta.y)/2;
	while (p1.x != p2.x || p1.y != p2.y) 
	{
		my_pixel_put(fdf, p1.x, p1.y, 0xFFFFFF);
		e2 = err;
		if (e2 > -delta.x)
		{
			err -= delta.y;
			p1.x += sign.x;
		}
		if (e2 < delta.y)
		{
			err += delta.x;
			p1.y += sign.y;
		}
	}
}

void	draw(t_mlx *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (x != data->map->width - 1)
				draw_line(data, project(new_point(x, y, data->map), data->map),
					project(new_point(x + 1, y, data->map), data->map));
			if (y != data->map->height - 1)
				draw_line(data, project(new_point(x, y, data->map), data->map),
					project(new_point(x, y + 1, data->map), data->map));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
