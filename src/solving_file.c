/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:10:56 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/24 12:33:39 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*solve(t_list *tet)
{
	t_map	*result;
	size_t	size;

	result = map_init(2);
	while (!place_all(result, tet))
	{
		size = result->size;
		ft_memdel((void**)&result);
		result = map_init(++size);
	}
	return (result);
}

t_bool	place_all(t_map *map, t_list *tet)
{
	t_point	loc;
	char	**content;

	if (!tet)
		return (TRUE);
	content = tet->content;
	loc.x = 0;
	loc.y = 0;
	while (loc.x < (int)map->size)
	{
		loc.y = 0;
		while (loc.y < (int)map->size)
		{
			if (check_tetro(content, map, loc))
			{
				set_tetro(content, map, loc, content[4][0]);
				if (place_all(map, tet->next))
					return (TRUE);
				set_tetro(content, map, loc, '.');
			}
			loc.y++;
		}
		loc.x++;
	}
	return (FALSE);
}
