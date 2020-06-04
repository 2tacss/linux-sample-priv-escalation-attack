#include <stdio.h>
#include <string.h>
#include "fileman/fileman.h"
#include "exception/exception.h"
#include "def.h"

#define PASSWD_BUF_SIZE	16

int is_auth(char passwd_buf[]) {
	char *passwd = "asd";

	if (strcmp(passwd_buf, passwd) == 0) {
		return E_SUCCESS;
	}
	return E_FAILURE;
}

int main(int argc, char *argv[]) {
	int fd;
	char passwd_buf[PASSWD_BUF_SIZE] = {0};
	int is_auth_flag = 0;
	char *rbuf = 0;

	strcpy(passwd_buf, argv[1]);
	is_auth_flag = is_auth(passwd_buf);
	
	if (is_auth_flag > 0) {
		int code = return_code(E_SUCCESS, "Granted Access.");
		if (code == E_SUCCESS) {
			fd = openfile();
			rdfile(fd, rbuf);
			printf(rbuf);
			closefile(fd);
			return code;
		}
	} else {
			int code = return_code(E_FAILURE, "Denied Access.");
			return code;
		}

		return E_SUCCESS;
	}
