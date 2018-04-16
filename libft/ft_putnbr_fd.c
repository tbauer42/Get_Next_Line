/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:23:38 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/16 11:23:46 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*chain;
	int		i;

	chain = "-2147483648";
	i = 0;
	if (n == -2147483648)
	{
		while (i < 11)
		{
			ft_putchar_fd(chain[i++], fd);
		}
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
	}
	ft_putchar_fd(((n % 10) + 48), fd);
}
