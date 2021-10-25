/* become_daemon.h */
#ifndef BECOME_DAEMON_H         /* prevent double inclusion */
#define BECOME_DAEMON_H

/* Bit-mask values for 'flags' argument of becomeDaemon() */

#define BD_NO_CHDIR                     01
#define BD_NO_CLOSE_FILES               02
#define BD_NO_REOPEN_STD_FDS            04

#define BD_NO_UMASK0                   010

#define BD_MAX_CLOSE                  8192

int becomeDaemon(int flags);


#endif