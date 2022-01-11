#include "monty.h"
/**
 *
 *
 *
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL; 
}
/**
 * instruction_t - instruction struct
 * @i: int pos the struct
 * Return: struct
 */
instruction_t fstruct(int i)
{
	instruction_t artype[] = {
		{"push", op_push},
		{"pop", op_pop},
		{"pint", op_pint},
		{"swap", op_swap},
		{"pall", op_pall},
		{"nop", op_nop},
		{NULL,NULL}
	};
	return (artype[i])
}
