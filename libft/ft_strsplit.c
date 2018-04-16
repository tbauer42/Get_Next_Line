/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:33:55 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/16 18:35:46 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_countword(char *str, char c)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c) && (str[i + 1] == c || str[i + 1] == '\0'))
			cpt++;
		i++;
	}
	return (cpt);
}

static int	size_word(int a, char *str, char c)
{
	int i;
	int cpt;
	int cpt2;

	i = 0;
	cpt = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c) && (str[i + 1] == c || str[i + 1] == '\0'))
			cpt++;
		if (a == cpt)
		{
			cpt2 = i;
			while (str[i] != c && str[i] > 0)
				i--;
			cpt2 = cpt2 - i;
			return (cpt2);
		}
		i++;
	}
	return (0);
}

static void	put_all(char **tab, char *str, int size_1, char c)
{
	int i;
	int j;
	int a;

	i = 0;
	j = 0;
	a = 0;
	while (i < size_1)
	{
		while (str[j] == c)
			j++;
		while (a < size_word((i + 1), str, c))
		{
			tab[i][a] = str[j];
			j++;
			a++;
		}
		tab[i][a] = '\0';
		a = 0;
		i++;
	}
	tab[i] = 0;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		size_1;
	int		size_2;
	int		i;
	int		j;

	if (s == NULL || !c)
		return (NULL);
	size_1 = ft_countword((char*)s, c);
	i = 0;
	size_2 = size_word((i + 1), (char*)s, c);
	j = 0;
	tab = malloc((size_1 + 1) * sizeof(char*));
	if (tab == NULL)
		return (0);
	while (i < size_1)
	{
		tab[i] = malloc(size_word((i + 1), (char*)s, c) * sizeof(char));
		i++;
	}
	put_all(tab, (char*)s, size_1, c);
	return (tab);
}
