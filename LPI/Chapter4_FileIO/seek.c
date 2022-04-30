#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "../tlpi_hdr.h"

int main(int argc, char *argv[])
{
	//size_t len;
	int fd, ap;
	//char *buff;
	size_t numWritten;

	fd = open(argv[1], O_RDWR | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fd == -1)
		errExit("open");

	for (ap =2; ap < argc; ap++)
	{

	numWritten = write(fd, &argv[ap][1], strlen(&argv[ap][1]));
	if (numWritten == -1)
		errExit("write");
	printf("%s: wrote %ld bytes\n", argv[ap], (long) numWritten);
	}

	return 0;

}
