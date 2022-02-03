/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 08:19:53 by rburri            #+#    #+#             */
/*   Updated: 2022/02/03 10:48:45 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		get_index(int x, int y, int width)
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


void my_pixel_put(t_mlx *fdf, int x, int y, int color)
{
	char *pixel;

	pixel = fdf->addr + (y * fdf->line_length + x * (fdf->bit_per_pixel / 8));
	*(unsigned int*)pixel = color;
}

void draw_line(t_mlx *fdf, t_point f, t_point s) 
{
	t_point delta;
	t_point sign;
	t_point cur;
	int 	error[2];
	
	delta.x = FT_ABS(s.x - f.x);
	delta.y = FT_ABS(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y) 
	{
		my_pixel_put(fdf, cur.x, cur.y, 0xFFFFFF);
		if ((error[1] == error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

// void		draw(t_map *map, t_mlx *fdf)
// {
// 	int		x;
// 	int		y;

// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			if (x != map->width - 1)
// 				draw_line(fdf, project(new_point(x, y, map), map),
// 					project(new_point(x + 1, y, map), map));
// 			if (y != map->height - 1)
// 				draw_line(fdf, project(new_point(x, y, map), map),
// 					project(new_point(x, y + 1, map), map));
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
// }

// int draw_square(t_mlx *fdf, int beginX, int beginY, int length, int color)
// {
// 	int len;
// 	int pixelX;
// 	int pixelY;
	
// 	pixelX = beginX;
// 	pixelY = beginY;
// 	len = length;
// 	while (len >= 0)
// 	{
// 		my_pixel_put(fdf, pixelX, pixelY, color);
// 		my_pixel_put(fdf, pixelX, pixelY + length, color);
// 		pixelX++;
// 		len--;
// 	}
// 	len = length;
// 	while (len >= 0)
// 	{
// 		my_pixel_put(fdf, pixelX - 1, pixelY, color);
// 		my_pixel_put(fdf, pixelX - length - 1, pixelY, color);
// 		pixelY++;
// 		len--;
// 	}
// 	return (0);
// }

// int draw_plain_square(t_mlx *fdf, int beginX, int beginY, int length, int color)
// {
// 	int alen;
// 	int blen;
// 	int pixelX;
// 	int pixelY;
	
// 	pixelX = beginX;
// 	pixelY = beginY;
// 	alen = length;
	
// 	while (alen >= 0)
// 	{
// 		blen = length;
// 		while (blen >= 0)
// 		{
// 			my_pixel_put(fdf, pixelX, pixelY, color);
// 			pixelX++;
// 			blen--;
// 		}
// 		pixelX = beginX;
// 		pixelY++;
// 		alen--;
// 	}
// 	return (0);
// }
