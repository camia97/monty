#include "monty.h"
/**
 *op_push - push to the stack function.
 *@stack: stack.
 *@line_n: number of lines value.
 */
void op_push(stack_t **stack, unsigned int line_n)
{
	stack_t *new_node;
	char *val;

	val = strtok(NULL, " ");
	if (!val || atoi_comp(val) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_n);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->n = atoi(val);
	new_node->next = (*stack);
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
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

	while (tmp)
	{
		fprintf(stdout, "%d\n", (tmp)->n);
		tmp = (tmp)->next;
		i++;
	}
}
/**
 * op_pint - print int.
 * @stack: stack.
 * @line_n: line number.
 */
void op_pint(stack_t **stack, unsigned int line_n)
{
	if (!*stack)
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_n);

	fprintf(stdout, "%d\n", (*stack)->n);
}
/**
 * op_nop - nop function.
 * @stack:stack.
 * @line_n:line number.
 * Return: void.
 */
void op_nop(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;
}
/**
 * op_pop - delete first node
 * @stack: stack
 * @line_n: number of lines
 */
void op_pop(stack_t **stack, unsigned int line_n)
{

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_n);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		free(*stack);
		(*stack) = NULL;
		return;
	}
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
