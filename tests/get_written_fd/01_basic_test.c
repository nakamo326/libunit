#include "../cases.h"

int	get_written_fd_basic_test(void)
{
	char	buf[10];
	char	*str;
	int		fd;
	bool	result;

	str = "aiueo";
	fd = ft_get_written_fd(str);
	read(fd, &buf, 5);
	buf[5] = '\0';
	result = strcmp(buf, str);
	close(fd);
	if (result)
		return (0);
	else
		return (-1);
}
