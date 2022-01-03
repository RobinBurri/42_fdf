/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:16:01 by rburri            #+#    #+#             */
/*   Updated: 2022/01/03 07:50:28 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <fcntl.h>

int main(int ac, char *av[])
{
	t_mlx	*fdf;
	char *s = "HELLO";

	// fd = open(av[1], O_RDONLY);
	// if (fd == -1)
	// 	send_err(OPEN_ERR);
	fdf = fdf_init();
	my_mlx_pixel_put(fdf, 5, 5, 0x00FF0000);
	mlx_string_put(fdf->mlx, fdf->win, 550, 50, 0x00FFFFFF, s);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_loop(fdf->mlx);
	return  (0);
}