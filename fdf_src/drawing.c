/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 08:19:53 by rburri            #+#    #+#             */
/*   Updated: 2022/02/02 08:41:23 by rburri           ###   ########.fr       */
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
	char *dst;

	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int draw_line(t_mlx *fdf, t_point s, t_point f) {
	t_point delta;
	t_point pixel;
	t_point cur;
	int pixels;
	int error;
	
	delta.x = FT_ABS(f.x - s.x);
	delta.y = FT_ABS(f.y - s.y);
	pixel.x = s.x;
	pixel.y = s.y;
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	while (pixels) {
		my_pixel_put(fdf, pixel.x, pixel.y, 0xFFFFFF);
		pixel.x += delta.x;
		pixel.y += delta.y;
		--pixels;
	}
	return (0);
}

void		draw(t_map *map, t_mlx *fdf)
{
	int		x;
	int		y;

	// draw_background(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != map->width - 1)
				draw_line(fdf, project(new_point(x, y, map), map),
					project(new_point(x + 1, y, map), map));
			if (y != map->height - 1)
				draw_line(fdf, project(new_point(x, y, map), map),
					project(new_point(x, y + 1, map), map));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	// print_menu(fdf);
}

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
