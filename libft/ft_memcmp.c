/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:57:26 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/16 16:26:34 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*p1;
	const char	*p2;
	int			i;

	p1 = s1;
	p2 = s2;
	i = 0;
	while (n--)
	{
		if (p1[i] != p2[i])
			return ((unsigned char)(p1[i]) - (unsigned char)(p2[i]));
		i++;
	}
	return (0);
}
