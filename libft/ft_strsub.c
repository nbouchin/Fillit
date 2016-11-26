/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:23:45 by asenat            #+#    #+#             */
/*   Updated: 2016/11/10 16:20:32 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s || start > ft_strlen(s))
		return (NULL);
	if (!(result = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
		result[i++] = *(s++ + start);
	return (result);
}
