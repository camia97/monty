#ifndef _MONTY_H
#define _MONTY_H
#include <string.h>
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
	void (*f)(stack_t **stack, unsigned int line_n);
} instruction_t;
void op_push(stack_t **stack, unsigned int line_n);
void op_pall(stack_t **stack, unsigned int line_n);
void get_func(char *token, unsigned int line_n, stack_t **sta);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int read_files(FILE *op, stack_t **sta);
void op_pint(stack_t **stack, unsigned int line_n);
#endif
