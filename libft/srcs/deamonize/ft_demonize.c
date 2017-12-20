#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_deamonize.h"

static inline void	close_all_fds()
{
	int	maxfd;
	int	fd;

	maxfd = sysconf(_SC_OPEN_MAX);
	if (maxfd == -1)
		maxfd = D_MAX_CLOSE;
	fd = 0;
	while (fd < maxfd)
		close(fd++);
}

static inline int	reopen_fds(void)
{
	int	fd;

	close(STDIN_FILENO);
	fd = open("/dev/null", O_RDWR);
	if (fd != STDIN_FILENO)
		return (-1);
	if (dup2(STDIN_FILENO, STDOUT_FILENO) != STDOUT_FILENO)
		return (-1);
	if (dup2(STDIN_FILENO, STDERR_FILENO) != STDERR_FILENO)
		return (-1);
	return (0);
}

int				ft_deamonize(int flags)
{
	int	pid;

	if ((pid = fork()) == -1)
		return (-1);
	else if (pid > 0)
		_exit(EXIT_SUCCESS);
	if (setsid() == -1)
		return (-1);
	if ((pid = fork()) == -1)
		return (-1);
	else if (pid > 0)
		_exit(EXIT_SUCCESS);
	if (setsid() == -1)
		return (-1);
	if (!(flags & D_NO_UMASK0))
		umask(0);
	if (!(flags & D_NO_CHDIR))
		chdir("/");
	if (!(flags & D_NO_CLOSE_FILES))
		close_all_fds();
	if (!(flags & D_NO_REOPEN_STD_FDS))
		if (reopen_fds() == -1)
			return (-1);
	return (0);
}