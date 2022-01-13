#include "monty.h"
/**
 * get_func - obtain the instruction in the struct.
 * @token: token.
 * @sta: stack.
 * @line_n: numbers of lines.
 */
void get_func(char *token, unsigned int line_n, stack_t **sta)
{
	int i = 0;

	instruction_t artype[] = {
	{"push", op_push},
	{"pall", op_pall},
	/*{"pop", op_pop},
	{"pint", op_pint},
	{"swap", op_swap},
	{"nop", op_nop},*/
	{NULL, NULL}
	};
	while (artype[i].opcode)
	{
		if (strcmp(artype[i].opcode, token))
		{
			artype[i].f(sta, line_n);
			break;
		}
		i++;
	}
	if (!artype[i].opcode)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_n, artype[i].opcode);
		exit(EXIT_FAILURE);
	}
}
