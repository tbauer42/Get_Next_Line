#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/type.h>
#include <unistd.h>

#define BUFF_SIZE 1000

int	get_next_line(const int fd, char **line);

#endif
