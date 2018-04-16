/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:18:49 by tbauer            #+#    #+#             */
/*   Updated: 2018/04/16 19:40:20 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

int		ft_error(char **str, char **line, int fd)
{
	if (fd == -1 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (!*str)
	{
		if (!(*str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	}
	return (0);
}

char	*read_it(char *str, int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*dr_freeman;
	int		ret;

	if (fd == 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			dr_freeman = str;
			str = ft_strjoin(str, buf);
			free(dr_freeman);
		}
	}
	else
	{
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			dr_freeman = str;
			str = ft_strjoin(str, buf);
			free(dr_freeman);
		}
	}
	if (ret < 0)
		return (NULL);
	return (str);
}

void	get_norm(char **line, char **str, char **str_free, int i)
{
	(*line) = ft_strsub(*str, 0, i);
	*str_free = ft_strdup(*str + i + 1);
	free(*str);
	*str = ft_strdup(*str_free);
	free(*str_free);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	int			i;
	char		*str_free;

	if (ft_error(&str, line, fd) == -1)
		return (-1);
	if (*str && *line)
		ft_strcpy(*line, str);
	if ((str = read_it(str, fd)) == NULL)
		return (-1);
	i = 0;
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		get_norm(line, &str, &str_free, i);
		return (1);
	}
	else
		(*line) = ft_strdup("");
	return (0);
}
