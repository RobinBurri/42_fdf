/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 08:19:53 by rburri            #+#    #+#             */
/*   Updated: 2022/01/05 05:33:29 by rburri           ###   ########.fr       */
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
		my_pixel_put(fdf, pixelX - 1, pixelY, color);
		my_pixel_put(fdf, pixelX - length - 1, pixelY, color);
		pixelY++;
		len--;
	}
	return (0);
}
int draw_plain_square(t_mlx *fdf, int beginX, int beginY, int length, int color)
{
	int alen;
	int blen;
	int pixelX;
	int pixelY;
	
	pixelX = beginX;
	pixelY = beginY;
	alen = length;
	
	while (alen >= 0)
	{
		blen = length;
		while (blen >= 0)
		{
			my_pixel_put(fdf, pixelX, pixelY, color);
			pixelX++;
			blen--;
		}
		pixelX = beginX;
		pixelY++;
		alen--;
	}
	return (0);
}

int draw_triangle(t_mlx *fdf, int beginX, int beginY, int height, int color)
{
	int alen;
	int blen;
	int pixelXS;
	int pixelYS;
	int pixelXE;
	int pixelYE;
	
	pixelXS = beginX;
	pixelYS = beginY;
	pixelXE = beginX;
	pixelYE = beginY;
	alen = 0;
	

	draw_line(fdf, pixelXS, pixelYS, pixelXE/2, pixelYE/2, color);
	draw_line(fdf, pixelXS, pixelYS, (pixelXE + (pixelXE/2)), (pixelYE - (pixelYE/2)), color);
	draw_line(fdf, (pixelXE/2), (pixelYE/2), (pixelXE + (pixelXE/2)), (pixelYE - (pixelYE/2)),  color);

	return (0);
}