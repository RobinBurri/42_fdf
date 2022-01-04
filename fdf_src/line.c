/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 08:19:53 by rburri            #+#    #+#             */
/*   Updated: 2022/01/04 11:05:56 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void my_pixel_put(t_mlx *fdf, int x, int y, int color)
{
	char *dst;

	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int draw_line(t_mlx *fdf, int beginX, int beginY, int endX, int endY, int color) {
	double	deltaX;
	double	deltaY;
	double	pixelX;
	double	pixelY;
	int pixels;
	
	deltaX = endX - beginX;
	deltaY = endY - beginY;
	pixelX = beginX;
	pixelY = beginY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels) {
		my_pixel_put(fdf, pixelX, pixelY, color);
		pixelX -= deltaX;
		pixelY -= deltaY;
		--pixels;
	}
	return (0);
}

int draw_square(t_mlx *fdf, int beginX, int beginY, int length, int color)
{
	int len;
	int pixelX;
	int pixelY;
	
	pixelX = beginX;
	pixelY = beginY;
	len = length;
	while (len >= 0)
	{
		my_pixel_put(fdf, pixelX, pixelY, color);
		my_pixel_put(fdf, pixelX, pixelY + length, color);
		pixelX++;
		len--;
	}
	len = length;
	while (len >= 0)
	{
		my_pixel_put(fdf, pixelX, pixelY, color);
		my_pixel_put(fdf, pixelX - length, pixelY, color);
		pixelY++;
		len--;
	}
	return (0);
}