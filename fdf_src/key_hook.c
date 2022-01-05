/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:30:20 by rburri            #+#    #+#             */
/*   Updated: 2022/01/05 06:14:51 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_hook(int keycode, t_mlx *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit (0);
	}
	else
	{
		ft_putstr("Hello from key_hook no: ");
		ft_putnbr_fd(keycode, 1);
		ft_putstr("\n");	
	}
		return (0);
}