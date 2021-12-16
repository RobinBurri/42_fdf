/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:16:01 by rburri            #+#    #+#             */
/*   Updated: 2021/12/16 16:13:24 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>


int	key_hook(int keycode, t_data img)
{
	printf("Hello from key_hook!\n");
}

int mouse_hook(int button, int x, int y, t_data img)
{
	printf("x: %d, y: %d , button: %d\n", x , y, button);
}



int main(int ac, char *av[])
{
	t_data	img;
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HIGHT, TITLE);
	
	img.img = mlx_new_image(vars.mlx, WIDTH, HIGHT);
	
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_key_hook(vars.win, mouse_hook, &vars);
	
	mlx_loop(vars.mlx);
	return  (0);
}