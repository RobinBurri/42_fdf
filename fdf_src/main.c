/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:16:01 by rburri            #+#    #+#             */
/*   Updated: 2022/01/04 11:50:51 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <fcntl.h>

int main(int ac, char *av[])
{
	t_mlx	*fdf;

	// fd = open(av[1], O_RDONLY);
	// if (fd == -1)
	// 	send_err(OPEN_ERR);
	fdf = fdf_init();
	draw_triangle(fdf, 500, 500, 50, 0xffffff);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_loop(fdf->mlx);
	return  (0);
}