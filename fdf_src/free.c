/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:20:53 by rburri            #+#    #+#             */
/*   Updated: 2022/02/03 11:23:42 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void ft_free_stack(t_point *stack)
{
		t_point *tmp;
		tmp = stack;
		while (tmp != NULL)
		{
			tmp = stack->next;
			free(stack);
			stack = tmp;
		}
}

void	ft_free_map(t_map *map)
{
	free(map->coords_arr);
	free(map->camera);
	free(map);
}
