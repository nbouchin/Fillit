/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:46:39 by asenat            #+#    #+#             */
/*   Updated: 2016/11/24 11:20:30 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_all(char *path)
{
	int			fd;
	static char	buf[MAX_TET * 21];
	int			i;
	int			last;

	last = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	read(fd, &buf, MAX_TET * 21);
	close(fd);
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n' && buf[i + 1] == '\n')
		{
			if (i - last != 19 && i - last != 21)
				return (NULL);
			last = i;
		}
		i++;
	}
	buf[i] = '\n';
	if (ft_strstr(buf, "\n\n\n"))
		return (NULL);
	return (buf);
}

char	**alloc_tet(char **split, int *i)
{
	char	**res;
	int		y;

	if (!(res = (char**)ft_memalloc(sizeof(char*) * 6)))
		return (NULL);
	y = 0;
	res[5] = 0;
	while (y++ < 4)
	{
		if (!(*res = ft_strnew(4)))
		{
			free(res);
			return (NULL);
		}
		ft_strcpy(*res, split[*i]);
		res++;
		(*i)++;
	}
	if (!(*res = ft_strnew(1)))
	{
		free(res);
		return (NULL);
	}
	**res = (*i) / 4 + 'A' - 1;
	return (res - 4);
}

t_list	*getlist(char *buf)
{
	t_list	*list;
	char	**split;
	int		i;
	char	**tmp;

	if (ft_strlen(buf) % 21 != 0)
		return (NULL);
	list = NULL;
	i = 0;
	split = ft_strsplit(buf, '\n');
	while (split[i])
	{
		if (!(tmp = alloc_tet(split, &i)) || !is_tetro(tmp))
			return (NULL);
		if (!list)
			list = ft_lstnew((void*)tmp, 5 * sizeof(tmp));
		else
			ft_lstadd(&list, ft_lstnew((void*)tmp, 5 * sizeof(tmp)));
	}
	ft_lstrev(&list);
	return (list);
}
