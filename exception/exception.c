#include <stdio.h>
#include <string.h>
#include "exception.h"
#include "../def.h"

void show_colored_msg(char *key, char *msg, char *color) {
	char *white = "\x1b[39m";
	printf("%s[%s]: %s%s\n", color, key, white, msg);
	return;
}

int return_code(int type, char *msg) {
	if (type > E_TYPE_LENGTH) {
		return E_VALUE;
	}

	char *red = "\x1b[31m";
	char *green = "\x1b[32m";

	switch(type) {
		case E_SUCCESS:
			show_colored_msg("SUCCESS", msg, green);
			return E_SUCCESS;
		case E_FAILURE:
			show_colored_msg("FAILURE", msg, red);
			return E_FAILURE;
		case E_FILE_OPEN:
			show_colored_msg("FILE_OPEN", msg, red);
			return E_FILE_OPEN;
		case E_FILE_READ:
			show_colored_msg("FILE_READ", msg, red);
			return E_FILE_READ;
			break;
		case E_FILE_CLOSE:
			show_colored_msg("FILE_CLOSE", msg, red);
			return E_FILE_CLOSE;
		case E_VALUE:
			show_colored_msg("VALUE", msg, red);
			return E_VALUE;
			break;
		case E_RANGE:
			show_colored_msg("RANGE", msg, red);
			return E_RANGE;
		default:
			break;
	}
}

