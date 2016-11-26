/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:48:03 by asenat            #+#    #+#             */
/*   Updated: 2016/11/08 16:59:50 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isblank(char c)
{
	return (c == '\n' || c == ' ' || c == '\f' || c == '\t' || c == '\v' ||
			c == '\r');
}

int			ft_atoi(char const *s)
{
	int result;
	int i;
	int neg;

	neg = 1;
	i = 0;
	result = 0;
	while (isblank(s[i]))
		i++;
	if (s[i] == '-')
		neg = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] && (ft_isdigit(s[i]) == 1))
	{
		result *= 10;
		result += s[i] - '0';
		i++;
	}
	return (result * neg);
}
