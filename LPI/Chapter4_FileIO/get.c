#include <stdio.h>


int main(int argc, char *argv[])
{


	int c = getc(stdin);
	printf("getc():c was assigned %c\n", c);

	// only one works at a time for some reason, it returns?
	int ch = getchar();
	printf("getchar(): ch was assigned %c\n", ch);

	int fg = fgetc(stdin);
	printf("fgetc(): fg was assigned %c\n", fg);


	return 0;
}
