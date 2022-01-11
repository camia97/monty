#include "monty.h"
int main(int argc, char **argv)
{
	FILE *op;
	char *token, *line, buffer[];
	int i = 0, size = 1024, count_line = 0;

	op = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n", errno);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, stdin) != -1)
	{
		token = strtok(buffer, " ");
		get_func(token);
		i++;
		count_line++;
	}
	close(op);
}
