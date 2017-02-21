/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:45:13 by abonneca          #+#    #+#             */
/*   Updated: 2017/02/21 16:54:17 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*ft_eval_path(t_path *paths,
		t_link *new_way, t_box *current_box, t_box *end)
{
	t_link	*links;
	t_link	*cpy_way;
	t_link	*tmp;

	links = current_box->links;
	if (current_box == end)
	{
		ft_add_path(&paths, new_way);
		return (paths);
	}
	while (links)
	{
		if (!links->box->visited)
		{
			tmp = ft_new_way(links->box);
			ft_add_link(&new_way, tmp);
			current_box->visited = 1;
			paths = ft_eval_path(paths, new_way, links->box, end);
			free(tmp);
			current_box->visited = 0;
		}
		links = links->next;
	}
	return (paths);
}

t_path		*ft_find_paths(t_box **box, t_inf **inf)
{
	t_box	*start;
	t_box	*end;
	t_link	*new_way;
	t_path	*paths;

	start = ft_find_box(box, (*inf)->start);
	end = ft_find_box(box, (*inf)->end);
	paths = NULL;
	new_way = ft_new_way(start);
	paths = ft_eval_path(paths, new_way, start, end);
	if (paths != NULL)
		(*inf)->valid_map = 1;
	free(new_way);
	return (paths);
}
