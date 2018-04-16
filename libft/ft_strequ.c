/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:10:55 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/16 18:26:26 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	size_t i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while ((int)s1[i] == (int)s2[i] && s1[i] != '\0')
		i++;
	if (i == ft_strlen(s1) && i == ft_strlen(s2))
		return (1);
	return (0);
}
