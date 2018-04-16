/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:11:08 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/20 13:29:23 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char*str;

	str = (char *)s;
	while (*str != (unsigned char)c && *str != '\0')
		str++;
	if (*str == (unsigned char)c)
		return (str);
	return (0);
}
