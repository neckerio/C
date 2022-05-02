#include <stdio.h>
#include <stdlib.h>
// write(), works in the other files but it doesn't leave an EOL. I will try different variants. Like printf or maybe pwrite.


// 1. printf() - stdout
// 2. sprintf() - print to char buffer
// 3. snprintf() - print to char buffer with explicit "N" number of characters
// 4. fprintf() - write to file "streams"

int main(int argc, char* argv[])
{
	char buffer[30];
	char snbuffer[30];
	FILE *fptr;

	printf("from printf - random num %d\n", 5);

	sprintf(buffer, "from sprintf %d\n", 6);
	printf("%s\n", buffer);

	snprintf(snbuffer,30,"from sNprintf %d", 7);
	printf("%s\n", snbuffer);

	fptr = fopen(argv[1], "w");
	fprintf(fptr, "from fprtinf() %d\n", 5);


	return 0;
}

