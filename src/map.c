/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:38:06 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/24 09:29:09 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*map_init(size_t size)
{
	t_map	*map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->grid = create_grid(size, map);
	return (map);
}

char	**create_grid(size_t size, t_map *map)
{
	size_t	i;
	size_t	y;

	if (!(map->grid = (char**)ft_memalloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(map->grid[i] = ft_strnew(size)))
		{
			ft_memdel((void**)map->grid);
			return (NULL);
		}
		y = 0;
		while (y < size)
		{
			map->grid[i][y] = '.';
			y++;
		}
		i++;
	}
	return (map->grid);
}

void	map_del(t_map *map)
{
	size_t i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)map->grid[i]);
		i++;
	}
	ft_memdel((void **)map->grid);
}

void	print_map(t_map *map)
{
	size_t i;

	i = 0;
	while (i < map->size)
		ft_putendl(map->grid[i++]);
}
