/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 08:31:16 by rburri            #+#    #+#             */
/*   Updated: 2022/01/07 09:59:19 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split[i]);
}


static t_point	*new_pts(char *s)
{
	t_point	*pts;
	char		**parts;

	if (!(pts = (t_point *)ft_memalloc(sizeof(t_point))))
		send_err(MAP_ERR);
	if (!(parts = ft_split(s, ',')))
		send_err(MAP_ERR);
	pts->z = ft_atoi(parts[0]);
	pts->color = parts[1] ? ft_atoi_base(parts[1], 16) : -1;
	pts->next = NULL;
	// free_strsplit_arr(parts);
	return (pts);
}

static void	parse_line(char **coords_line, t_point **pts_stack,t_map *map)
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


int		read_map(int fd, t_point **pts_stack, t_map *map)
{
	char	*line;
	char	**coords_line;

	while ((line = get_next_line(fd)) != NULL)
	{
		coords_line = ft_split(line, ' ');
		if (!coords_line)
			send_err(MAP_ERR);
		parse_line(coords_line, pts_stack, map);
		free_split(coords_line);
		free(line);
		map->height++;
	}
}