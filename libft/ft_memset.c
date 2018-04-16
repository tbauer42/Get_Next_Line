/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:59:22 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/08 12:57:36 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char			*ps;
	unsigned char	pc;
	size_t			i;

	ps = s;
	pc = c;
	i = 0;
	while (i < n)
	{
		ps[i] = pc;
		i++;
	}
	return (s);
}
