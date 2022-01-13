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
	/* static char *hola;*/

	op = fopen(argv[1], "r");
	if (!op)
	{
		fprintf(stderr, "Error: Can't open file <argv[1]>");
		exit(EXIT_FAILURE);
	}
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, op) != -1)
	{
		token = strtok(buffer, " ");
		get_func(token, count_line, &sta);
		count_line++;
		free(buffer);
		buffer = NULL;
	}
	fclose(op);
	return (0);
}