#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static int cmpstringp(const void *p1, const void *p2)
{
	return strcmp(*(const char **)p1, *(const char **)p2);
}
int main(int argc, char *argv[])
{
	int j;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <string>...\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	qsort(&argv[1], argc - 1, sizeof(char *), cmpstringp);
	for (j = 1; j < argc; j++)
		puts(argv[j]);
	exit(EXIT_SUCCESS);
}
