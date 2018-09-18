#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

# define BUFF_SIZE 50

int		get_next_line(const int fd, char **line);

#endif
