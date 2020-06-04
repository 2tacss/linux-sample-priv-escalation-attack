#ifndef FILEMAN_H
#define FILEMAN_H

#define DB							"/your/path/db/id.db"
#define DB_BUFFER_SIZE 	16


extern int openfile(void);
extern int rdfile(int fd, char *db_buf);
extern int closefile(int fd);

# endif
