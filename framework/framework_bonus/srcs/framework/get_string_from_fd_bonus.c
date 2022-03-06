#include "libunit_bonus.h"
#include "unistd.h"
#include <stdlib.h>

char	*get_string_from_fd(int fd, size_t size)
{
	ssize_t	bufsize;
	ssize_t	readsize;
	ssize_t	read_status;
	char	*buf;

	bufsize = 0;
	readsize = 0;
	buf = NULL;
	while (42)
	{
		if (bufsize <= readsize)
		{
			bufsize += size;
			buf = or_exit(realloc(buf, bufsize));
		}
		read_status = read(fd, buf + readsize, size);
		if (read_status <= 0)
			break ;
		readsize += read_status;
	}
	buf[readsize] = '\0';
	return (buf);
}
