/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:55:56 by rburri            #+#    #+#             */
/*   Updated: 2022/01/03 07:49:02 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_mlx	*fdf_init(void)
{
	t_mlx	*fdf;
	
	fdf = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	if (!fdf)
		send_err(FDF_INIT_ERR);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		send_err(FDF_INIT_ERR);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HIGHT, TITLE);
	if (!fdf->win)
		send_err(FDF_INIT_ERR);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HIGHT);
	if (!fdf->img)
		send_err(FDF_INIT_ERR);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel, &fdf->line_length, &fdf->endian);
	if (!fdf->addr)
		send_err(FDF_INIT_ERR);
	return (fdf);
}
