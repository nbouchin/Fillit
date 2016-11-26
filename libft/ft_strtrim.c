/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:33:39 by asenat            #+#    #+#             */
/*   Updated: 2016/11/10 16:20:55 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	unsigned int	west;
	unsigned int	east;

	if (!s)
		return ("");
	east = ft_strlen(s) - 1;
	west = 0;
	while (isspace(s[west]))
		west++;
	if (!s[west])
		return (ft_strnew(1));
	while (isspace(s[east]))
		east--;
	east = (ft_strlen(s) - 1) - east;
	return (ft_strsub(s, west, (size_t)(ft_strlen(s) - (west + east))));
}
