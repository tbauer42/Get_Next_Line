/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:25:15 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/08 14:42:27 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	unsigned char	pc;
	size_t			i;

	ps = (unsigned char*)s;
	pc = c;
	i = 0;
	while (i < n)
	{
		if (ps[i] == pc)
			return (&ps[i]);
		i++;
	}
	return (NULL);
}
