#ifndef _MONTY_H
#define _MONTY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * split - function that split an argument
 * @argv: file to open
 * Return: the split string
 */
char *split(char *argv)
{
	char *token, *line, *op, buffer[];
	int i = 0, size = 1024, count_line = 0;

	op = open(argv[1], O_READONLY);
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
#endif
