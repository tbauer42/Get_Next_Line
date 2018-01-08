#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	int i = 0;
	char **line;

	if (line == NULL)
		printf("error");
	fd = open(argv[1], O_RDONLY);
	printf("%d\n", fd);
	printf("%d\n", get_next_line(fd, line));
	return 0;
}
