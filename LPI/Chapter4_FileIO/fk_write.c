#include "../tlpi_hdr.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int fd, ap;
	ssize_t numWritten;

	if (argc < 3 || strcmp(argv[1], "--help") == 0)
		usageErr("%s file {<string>}...\n", argv[0]);
	
	fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND, 
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
			S_IROTH | S_IWOTH);
	if (fd == -1)
		errExit("open");

	for (ap = 2; ap < argc; ap++)
	{	
	numWritten = write(fd, &argv[ap][0], strlen(&argv[ap][0]));
	if (numWritten == -1)
		errExit("write");
	
	printf("%s: wrote %ld bytes\n", argv[ap], (long) numWritten);

	}
	
	close(fd);

	exit(EXIT_SUCCESS);

}
