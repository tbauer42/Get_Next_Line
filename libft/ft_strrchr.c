/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:30:55 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/16 13:04:32 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	pc;
	int				len;
	char			*ps;

	pc = c;
	len = ft_strlen(s);
	ps = (char*)s;
	while (len >= 0)
	{
		if (ps[len] == pc)
			return (&ps[len]);
		len--;
	}
	return (NULL);
}
