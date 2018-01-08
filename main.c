#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	int i = 0;
	char *line;

	fd = open(argv[1], O_RDONLY);
	printf("%d\n", fd);
	while(get_next_line(fd, &line))
		printf("%s", line);
	return 0;
}
