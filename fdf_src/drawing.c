/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 08:19:53 by rburri            #+#    #+#             */
/*   Updated: 2022/01/06 08:10:41 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void my_pixel_put(t_mlx *fdf, int x, int y, int color)
{
	char *dst;

	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int draw_line(t_mlx *fdf, t_point s, t_point f, int color) {
	t_point delta;
	t_point pixel;
	int pixels;
	
	delta.x = FT_ABS(f.x - s.x);
	delta.y = FT_ABS(f.y - s.y);
	pixel.x = s.x;
	pixel.y = s.y;
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	while (pixels) {
		my_pixel_put(fdf, pixel.x, pixel.y, color);
		pixel.x += delta.x;
		pixel.y += delta.y;
		--pixels;
	}
	return (0);
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
