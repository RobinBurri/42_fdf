/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:37:35 by rburri            #+#    #+#             */
/*   Updated: 2022/02/04 11:45:59 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static	int	find_sign(int p1x, int p2x)
{
	if (p1x < p2x)
		return (1);
	else
		return (-1);
}

static int	find_err(int dx, int dy)
{
	if (dx > dy)
		return (dx / 2);
	else
		return (-dy / 2);
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
	sign.x = find_sign(p1.x, p2.x);
	sign.y = find_sign(p1.y, p2.y);
	err = find_err(delta.x, delta.y);
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
