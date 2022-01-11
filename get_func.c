#include "monty.h"
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
/**
 *
 *
 *
 */
void get_func(char *token, char **stack, unsigned int line_number)
{
	while (fstruct[i].opcode)
	{
		if (token == fstruct[i].opcode)
			fstruct[i].f(stack, line_number);
		i++;
	}
	if (!fstruct[i].opcode)
	{
		fprintf(stderr, "L<line_number>: unknown instruction <opcode>\n");
		exit(EXIT_FAILURE);
	}
}
