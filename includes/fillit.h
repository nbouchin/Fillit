/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:31:08 by asenat            #+#    #+#             */
/*   Updated: 2016/11/24 14:54:37 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# define MAX_TET 26
# include <unistd.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# define TRUE 1
# define FALSE 0
# define LEN(Value) ft_strlen(Value)

typedef int		t_bool;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_data
{
	t_point t_cord;
	t_point t_orig;
	t_point l_orig;
	int		dist;
	int		counter;
}				t_data;

typedef struct	s_map
{
	size_t	size;
	char	**grid;
}				t_map;

t_list			*getlist(char *buf);
char			*read_all(char *path);
t_map			*map_init(size_t size);
char			**create_grid(size_t size, t_map *map);
t_map			*solve(t_list *tet);
t_bool			place_all(t_map *map, t_list *tet);
int				print_error(void);
t_bool			is_validcar(char c);
t_bool			is_lineok(char *tmp);
int				is_out_of_bound(char **tmp, int x, int y);
t_bool			is_tetro(char **tmp);
void			print_map(t_map *map);
void			map_del(t_map *map);
t_point			p_init(int x, int y);
t_bool			check_tetro(char **tet, t_map *map, t_point loc);
void			set_tetro(char **tet, t_map *map, t_point loc, char c);

#endif
