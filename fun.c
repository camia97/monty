#include "monty.h"
/**
 *op_push - push to the stack function.
 *@stack: stack.
 *@line_number: number of lines value.
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->n = atoi(strtok(NULL, " "));
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack->prev = new_node;
}
/**
 *op_push - push to the stack function.
 *@stack: stack.
 *@line_number: number of lines value.
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
	{	fprintf(stdout, "%d\n", *stack->n);
		if (*stack->next)
			op_pall(*stack->next);
	}
}
