/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:37:26 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/13 18:46:44 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	char			*pdest;
	const char		*psrc;

	i = 0;
	pdest = (char*)dest;
	psrc = (char*)src;
	while (i < n)
	{
		pdest[i] = psrc[i];
		if ((unsigned char)pdest[i] == (unsigned char)c)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
