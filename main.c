#include "monty.h"
/**
 * main - main function.
 * @argc: argument counter.
 * @argv: argument vector.
 * Return: main.
 */
int main(int argc, char **argv)
{
	FILE *op;
	char *token, *buffer = NULL;
	int count_line = 1;
	size_t size = 1024;
	stack_t *sta = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	op = fopen(argv[1], "r");
	if (!op)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, op) != -1)
	{
		if (buffer[len(buffer) - 1] == '\n')
			buffer[len(buffer) - 1] = '\0';
		token = strtok(buffer, " ");
		if (token[0] == '#')
		{
			free(buffer), buffer = NULL, count_line++;
			continue;
		}
		if (token[0] == '\n')
		{
			free(buffer), buffer = NULL, count_line++;
			continue;
		}
		get_func(token, count_line, &sta), count_line++;
		free(buffer);
		buffer = NULL;
	}
	free(buffer), free_stack(&sta);
	fclose(op);
	return (0);
}
