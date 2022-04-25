#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "../tlpi_hdr.h"

int main(int argc, char *argv[])
{
	size_t len;
	int fd;
	char *buff;
	size_t numWritten;

	fd = open(argv[1], O_RDWR | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fd == -1)
		errExit("open");

	numWritten = write(fd, buff, len);


}
