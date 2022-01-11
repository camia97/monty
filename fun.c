/**
 * split - function that split an argument
 * @argv: file to open
 * Return: the split string
 */
char *split(char *argv)
{
	char *token, *line, *op, buffer[];
	int i = 0, size = 1024, count_line = 0;

	op = fopen(argv[1], "r");
	if (!buffer)
		exit(-1);
	while (token)
	{
		line = getline(&buffer, &size, stdin);
		buffer[i] = token;
		token = strtok(line, " ");
		token = strtok(NULL, " ");
		i++;
		count_line++;
	}
	close(op);
	return (buffer);
}
