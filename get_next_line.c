<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:59:49 by vklaouse          #+#    #+#             */
/*   Updated: 2016/01/20 15:57:41 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_del(char **stk)
{
	if (stk != NULL)
	{
		free(*stk);
		*stk = NULL;
	}
	return (0);
}

static char	*ft_join(char *stk, char *buf)
{
	char		*tmp;

	tmp = stk;
	stk = ft_strjoin(tmp, buf);
	ft_strdel(&tmp);
	return (stk);
}

static char	*ft_sub(char *stk)
{
	char		*tmp;

	tmp = stk;
	stk = ft_strsub(tmp, ft_strchr(tmp, '\n') - tmp + 1, \
		ft_strlen(ft_strchr(tmp, '\n')));
	ft_strdel(&tmp);
	return (stk);
}

int			get_next_line(int const fd, char **line)
{
	static char	*stk[2147483647];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	ret = 1;
	if (BUFF_SIZE < 1 || !line || fd < 0)
		return (-1);
	if (!stk[fd])
		stk[fd] = ft_strnew(0);
	while (!(ft_strchr(stk[fd], '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		stk[fd] = ft_join(stk[fd], buf);
	}
	if (ret < 0)
		return (-1);
	*line = ft_strchr(stk[fd], '\n') ? ft_strsub(stk[fd], 0, \
			ft_strchr(stk[fd], '\n') - stk[fd] + 1) : ft_strdup(stk[fd]);
	if (ft_strlen(*line) == 0)
		return (ft_del(&stk[fd]));
	if (ret)
		line[0][ft_strlen(*line) - 1] = '\0';
	stk[fd] = ft_sub(stk[fd]);
	return (1);
=======
#include "libft/includes/libft.h"
#include "get_next_line.h"
#include <stdio.h>

static int	make_line(int const fd, char *buffer, char *stock[fd])
{
	int		ret;
	char	*temp;

	while ((ft_strchr(buffer, '\n') == NULL) &&
			(ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		temp = stock[fd];
		stock[fd] = ft_strjoin(temp, buffer);
		ft_strdel(&temp);
	}
	if (buffer)
		ft_strdel(&buffer);
	if (ret == -1)
		return (-1);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*stock[FD];
	char		*buffer;
	int			ret;
	char		*str;
	char		*tmp;

	buffer = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || buffer == NULL || BUFF_SIZE < 1)
		return (-1);
	if (stock[fd] == NULL)
		stock[fd] = ft_strnew(1);
	if ((ret = make_line(fd, buffer, stock)) == -1)
		return (-1);
	printf("stok = %s\n", stock[fd]);
	if ((str = ft_strchr(stock[fd], '\n')) != NULL)
	{
		printf("str = %s\n", str);
		*line = ft_strsub(stock[fd], 0, str - stock[fd]);
		tmp = stock[fd];
		stock[fd] = ft_strdup(str + 1);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strdup(stock[fd]);
	stock[fd] = NULL;
	return (ft_strlen(*line) > 0 ? 1 : 0);
>>>>>>> 69d7bf4b5c4efda19b279e86bf85072804eb80b7
}
