#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	int i = 0;
	char *line;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line )>0)
		printf("%s", line);
	return 0;
}
