/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetros.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:07:35 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/24 12:58:30 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		p_init(int x, int y)
{
	t_point result;

	result.x = x;
	result.y = y;
	return (result);
}

t_bool		out_bounds(t_map *map, t_point loc)
{
	return (loc.y < 0 || loc.y > (int)map->size || loc.x >= (int)map->size);
}

t_bool		check_tetro(char **tet, t_map *map, t_point loc)
{
	t_data d;

	d.t_cord.x = -1;
	d.t_orig.y = -1;
	d.l_orig.y = loc.y;
	d.counter = 0;
	while (++(d.t_cord.x) < 4)
	{
		d.t_cord.y = -1;
		d.dist = 4 - LEN(ft_strstr(tet[d.t_cord.x], "#"));
		if (d.t_orig.y != -1)
			loc.y = d.l_orig.y + ((d.dist != d.t_orig.y) ?
					d.dist - d.t_orig.y : 0);
		while (tet[d.t_cord.x][++(d.t_cord.y)])
		{
			if (d.t_orig.y == -1 && tet[d.t_cord.x][d.t_cord.y] == '#')
				d.t_orig.y = d.t_cord.y;
			if (d.t_orig.y != -1 && tet[d.t_cord.x][d.t_cord.y] == '#' &&
					!out_bounds(map, loc) && map->grid[loc.x][loc.y++] == '.')
				d.counter++;
		}
		if (d.t_orig.y != -1)
			loc.x++;
	}
	return (d.counter == 4);
}

void		set_tetro(char **tet, t_map *map, t_point loc, char val)
{
	int		y;
	int		x;
	t_point	t_orig;
	t_point	l_orig;
	int		dist;

	x = -1;
	t_orig.y = -1;
	l_orig.y = loc.y;
	while (++x < 4)
	{
		y = -1;
		dist = 4 - LEN(ft_strstr(tet[x], "#"));
		if (t_orig.y != -1)
			loc.y = l_orig.y + ((dist != t_orig.y) ? dist - t_orig.y : 0);
		while (tet[x][++y])
		{
			if (t_orig.y == -1 && tet[x][y] == '#')
				t_orig.y = y;
			if (t_orig.y != -1 && tet[x][y] == '#')
				map->grid[loc.x][loc.y++] = val;
		}
		if (t_orig.y != -1 && (loc.x + 1) < (int)map->size)
			loc.x++;
	}
}
