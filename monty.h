#ifndef _MONTY_H
#define _MONTY_H

#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
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
 * read_textfile - read a function and prints it to the POSIX.
 * @filename:pointer value.
 * @letters: size of the string.
 * Return:text file.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf;
	int rl;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters)

	if (buf == NULL)
		return (0);

	fd = open(filename, O_RDONLY, 0600);

	if (fd == -1)
		return (0);

	rl = read(fd, buf, letters);
	write(STDOUT_FILENO, buf, rl);

	close(fd);
	free(buf);
	return (rl);
}
#endif
