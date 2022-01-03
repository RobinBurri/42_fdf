/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:30:20 by rburri            #+#    #+#             */
/*   Updated: 2022/01/03 10:48:28 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_hook(int keycode, t_mlx img)
{
	if (keycode == 53)
		mlx_destroy_window(img.mlx, img.win);
	return (keycode);
}