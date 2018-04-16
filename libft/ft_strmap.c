/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:38:07 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/16 18:23:52 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	i = -1;
	if (s == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[++i])
		str[i] = (*f)(s[i]);
	str[i] = '\0';
	return (str);
}
