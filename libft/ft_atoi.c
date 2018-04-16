/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:31:52 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/16 15:44:20 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 0;
	result = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
			|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - 48);
	if (sign == -1)
		return (-result);
	else
		return (result);
}
