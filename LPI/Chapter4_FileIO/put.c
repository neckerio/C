#include <stdio.h>



int main(int argc, char *argv[])
{

	int res;
	char str[] = "блин!";

	putchar('c');
	putc('D', stdout);
	res = putc('E',stdin);
	if (res == EOF)
		printf("ERROR\n");
	fputc('f', stdout);
	puts(str);
	puts(str);
	puts(str);
	puts(str);


	fputs(str, stdout);
	fputs(str, stdout);
	fputs(str, stdout);
	



	return 0;
}
