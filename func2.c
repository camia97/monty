#include "monty.h"
/**
 * op_swap - swap two elements.
 * @stack: stack.
 * @line_n: line number.
 */
void op_swap(stack_t **stack, unsigned int line_n)
{
	int aux;

	if (*stack)
	{
		if (!(*stack)->prev && !(*stack)->next)
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_n);
			exit(EXIT_FAILURE);
		}
		aux = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = aux;
	}
}
