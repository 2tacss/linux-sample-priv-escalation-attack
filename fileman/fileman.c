#include "fileman.h"
#include "../exception/exception.h"
#include "../def.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int openfile(void) {
	int fd;

	fd = open(DB, O_RDONLY);
	if (fd < 0) {
		int ret = return_code(E_FILE_OPEN, "Unable to open a file.(-1)");
		return ret;
	}

	printf("[Opened file]: \x1b[33m%s\x1b[39m\n", DB);

	return fd;
}

int rdfile(int fd, char *db_buf) {
	if (fd < 0) {
	int ret = return_code(E_FILE_OPEN, "Wrong your descriptor.");
		return ret;
	}

	size_t db_buf_size = (size_t)DB_BUFFER_SIZE;
	ssize_t len = 0;

	read(fd, db_buf, db_buf_size);

		return E_SUCCESS;
} 

int closefile(int fd) {
	if (fd < 0) {
		int ret = return_code(E_FILE_CLOSE, "Wrong your descriptor");
		return ret;
	}

	close(fd);
	return E_SUCCESS;
}
