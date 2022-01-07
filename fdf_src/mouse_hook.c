/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 09:50:45 by rburri            #+#    #+#             */
/*   Updated: 2022/01/07 09:56:40 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int mouse_hook(int button, int x, int y, t_mlx *fdf)
{	
	ft_putstr("X: ");
	ft_putnbr_fd(x, 1);
	ft_putstr(" Y: ");
	ft_putnbr_fd(y, 1);
	ft_putstr("\n");


	return (0);
}