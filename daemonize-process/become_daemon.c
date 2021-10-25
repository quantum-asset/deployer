/* become_daemon.c */
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "become_daemon.h"
/*
 * Returns 0 on success, -1 on error
 */
int becomeDaemon(int flags)
{
    int maxfd, fd;

    // Become backgorund process
    switch (fork())
    {
    case -1:
        return -1;
    case 0:
        break; //child fall through
    default:
        _exit(EXIT_SUCCESS); //while parent terminates
    }

    // Become leader of new session
    if (setsid() == -1)
        return -1;

    // Ensure we are not sessio leader
    switch (fork())
    {
    case -1:
        return -1;
    case 0:
        break;
    default:
        _exit(EXIT_SUCCESS);
        break;
    }

    // Clear file mode creation mask
    if (!(flags & BD_NO_UMASK0))
    {
        umask(0);
    }

    // change to root directory
    if (!(flags & BD_NO_CHDIR))
    {
        chdir("/");
    }

    // Close all open files
    if (!(flags & BD_NO_CLOSE_FILES))
    {
        maxfd = sysconf(_SC_OPEN_MAX);
        // Limite is indeterminate...
        // so take a guess
        if (maxfd == -1)
        {
            maxfd = BD_MAX_CLOSE;
        }
        for (fd = 0; fd < maxfd; fd++)
        {
            close(fd);
        }
    }

    if (!(flags & BD_NO_REOPEN_STD_FDS))
    {
        // Reopen standard fdf's to  /dev/null
        close(STDIN_FILENO);

        fd = open("/dev/null", O_RDWR);

        if (fd != STDIN_FILENO) // fd should be 0
            return -1;

        if (dup2(STDIN_FILENO, STDOUT_FILENO) != STDOUT_FILENO)
            return -1;
        if (dup2(STDIN_FILENO, STDERR_FILENO) != STDERR_FILENO)
            return -1;
    }

    return 0;
}