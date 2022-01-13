#include "monty.h"
/**
 *op_push - push to the stack function.
 *@stack: stack.
 *@line_n: number of lines value.
 */
void op_push(stack_t **stack, unsigned int line_n)
{
	stack_t *new_node;
	(void)line_n;

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->n = atoi(strtok(NULL, " "));
	new_node->next = (*stack);
	new_node->prev = NULL;
	if (*stack)
	{	(*stack)->prev = new_node;
	}
	(*stack) = new_node;

}
/**
 *op_pall - print all the stack elements.
 *@stack: stack.
 *@line_n: number of lines value.
 */
void op_pall(stack_t **stack, unsigned int line_n)
{
	int i = 0;
	stack_t *tmp = *stack;
	(void)line_n;

	while (tmp && (tmp)->next)
	{	fprintf(stdout, "%d\n", (tmp)->n);
		tmp = (tmp)->next;
		i++;
	}
}
