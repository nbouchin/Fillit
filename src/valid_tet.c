/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:12:45 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/25 14:51:03 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool	is_validcar(char c)
{
	if (c == '#' || c == '.')
		return (TRUE);
	else
		return (FALSE);
}

t_bool	is_lineok(char *tmp)
{
	int	i;

	i = 0;
	while (is_validcar(tmp[i]) && tmp[i] != '\0')
		i++;
	if (i == 4)
		return (TRUE);
	else
		return (FALSE);
}

int		is_out_of_bound(char **tmp, int x, int y)
{
	int	i;

	i = 0;
	if ((x - 1) >= 0 && tmp[x - 1][y] == '#')
		i++;
	if ((x + 1) <= 3 && tmp[x + 1][y] == '#')
		i++;
	if ((y - 1) >= 0 && tmp[x][y - 1] == '#')
		i++;
	if ((y + 1) <= 3 && tmp[x][y + 1] == '#')
		i++;
	return (i);
}

t_bool	is_tetro(char **tmp)
{
	int	x;
	int	y;
	int	j;
	int	i;

	x = -1;
	j = 0;
	i = 0;
	while (++x < 4)
	{
		y = -1;
		while (tmp[x][++y])
		{
			if (!is_lineok(tmp[x]))
				return (FALSE);
			if (tmp[x][y] == '#')
			{
				if (!is_out_of_bound(tmp, x, y) || !is_lineok(tmp[x]))
					return (FALSE);
				j++;
				i += is_out_of_bound(tmp, x, y);
			}
		}
	}
	return (j == 4 && i >= 6);
}
