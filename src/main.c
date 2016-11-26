/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:15:54 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/24 10:10:45 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		print_usage(char *path)
{
	int				fd;
	static char		buf[100];

	if ((fd = open(path, O_RDONLY)) == -1)
		return (print_error());
	read(fd, &buf, 100);
	close(fd);
	ft_putstr(buf);
	return (0);
}

int		print_error(void)
{
	ft_putstr_fd("error\n", 1);
	return (0);
}

int		main(int ac, char **av)
{
	char	*tet;
	t_list	*lst;
	t_map	*map;
	t_point	loc;

	loc.x = 4;
	loc.y = 3;
	if (ac != 2)
		return (print_usage("./extern_file.txt"));
	if (!(tet = read_all(av[1])))
		return (print_error());
	if (!(lst = getlist(tet)))
		return (print_error());
	if (!(map = solve(lst)))
		return (print_error());
	print_map(map);
	return (0);
}
