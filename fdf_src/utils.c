/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:19:10 by rburri            #+#    #+#             */
/*   Updated: 2022/02/04 08:30:27 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>
#include <errno.h>

void	send_err(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit (1);
}

void	push_pts(t_point **pts_stack, t_point *new_pts)
{
	if (pts_stack)
	{
		if (new_pts)
		{
			new_pts->next = *pts_stack;
			*pts_stack = new_pts;
		}
	}
}

t_point	*pop_pts(t_point **pts_stack)
{
	t_point	*pts;

	pts = NULL;
	if (pts_stack && *pts_stack)
	{
		pts = *pts_stack;
		*pts_stack = (*pts_stack)->next;
	}
	return (pts);
}

void	ft_print_stack(t_point *stack)
{
	t_point	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{	
		printf("%d\n", tmp->z);
		tmp = tmp->next;
	}
	free(tmp);
}
