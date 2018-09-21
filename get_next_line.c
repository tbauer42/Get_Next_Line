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
}
