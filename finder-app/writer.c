#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>

void openlog(const char *ident, int option, int facility);
void syslog(int priority, const char *format, ...);
void closelog(void);
//int open (const char *name, int flags);
//int open (const char *name, int flags, mode_t mode);
ssize_t write (int fd, const void *buf, size_t count);
int main (int argc, char *argv[])
{
	int fd;
	ssize_t nr;
	openlog(NULL,LOG_PID,LOG_USER);
	if (argc != 3) {
		syslog(LOG_ERR,"Invalid number of arguments %d\n", argc);
		return 1;
	}
	fd=open(argv[1], O_RDWR | O_CREAT, 0644);
	if (fd == -1){
		syslog(LOG_ERR, "Cannot open %s\n", argv[1]);
		return -1;
	}
	nr = write(fd, argv[2], strlen(argv[2]));
	syslog(LOG_DEBUG, "Writing %s to %s\n", argv[2], argv[1]);
	if (nr == -1) {
		syslog(LOG_ERR, "Cannot write\n");
		return -1;
	}
	return 0;
}
