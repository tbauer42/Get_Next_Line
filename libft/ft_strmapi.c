/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:00:35 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/16 18:24:17 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
