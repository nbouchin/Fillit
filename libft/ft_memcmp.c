/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:39:35 by asenat            #+#    #+#             */
/*   Updated: 2016/11/10 11:33:20 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *s1, void const *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	if (!c1 && !c2)
		return (0);
	while (n--)
		if (*c1++ != *c2++)
			return (*(c1 - 1) - *(c2 - 1));
	return (0);
}
