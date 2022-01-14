#include "monty.h"
/**
 * op_swap - swap two elements.
 * @stack: stack.
 * @line_n: line number.
 */
void op_swap(stack_t **stack, unsigned int line_n)
{
	int aux = 0;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = aux;
}
/**
 * op_add - add two nodes.
 * @stack: stack.
 * @line_n: line number.
 */
void op_add(stack_t **stack, unsigned int line_n)
{
	int sum = 0;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	op_pop(stack, line_n);

}
/**
 * op_sub - subtracts two elements.
 * @stack: stack.
 * @line_n: number of lines.
 */
void op_sub(stack_t **stack, unsigned int line_n)
{
	int sub = 0;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = sub;
	op_pop(stack, line_n);
}
/**
 * op_div - divide two elements.
 * @stack: stack.
 * @line_n:numbers of lines.
 */
void op_div(stack_t **stack, unsigned int line_n)
{
	int div;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	div = (*stack)->n;

	if (div == 0)
	{
		printf("L%u: division by zero\n", line_n);
		exit(EXIT_FAILURE);
	}
	op_pop(stack, line_n);
	(*stack)->n /= div;
}
/**
 * op_mul - multiplies  two elements of the node.
 * @stack: stack.
 * @line_n: line number.
 */
void op_mul(stack_t **stack, unsigned int line_n)
{
	int mul;

	if (!(*stack) || (*stack)->next)
	{
		printf("L%u: can't mul, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	mul = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = mul;
	op_pop(stack, line_n);

}
