/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 08:31:16 by rburri            #+#    #+#             */
/*   Updated: 2022/02/04 11:50:17 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split[i]);
}

static t_point	*new_pts(char *s)
{
	t_point	*pts;

	pts = (t_point *)ft_memalloc(sizeof(t_point));
	if (!pts)
		send_err(MAP_ERR);
	pts->z = ft_atoi(s);
	pts->next = NULL;
	return (pts);
}

static void	parse_line(char **coords_line, t_point **pts_stack, t_map *map)
{
	int	width;

	width = 0;
	while (*coords_line)
	{
		push_pts(pts_stack, new_pts(*(coords_line++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;
	else if (map->width != width)
		send_err(MAP_ERR);
}

int	read_map(int fd, t_point **pts_stack, t_map *map)
{
	char	*line;
	char	**coords_line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		coords_line = ft_split(line, ' ');
		if (!coords_line)
			send_err(MAP_ERR);
		parse_line(coords_line, pts_stack, map);
		free_split(coords_line);
		free(line);
		map->height++;
		line = get_next_line(fd);
	}
	return (0);
}
