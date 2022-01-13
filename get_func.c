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
	{"pint", op_pint},
	{"nop", op_nop},
	/*
	 * {"pop", op_pop},
	 * {"swap", op_swap},
	 */
	{NULL, NULL}
	};
	while (artype[i].opcode)
	{
		if (strncmp(artype[i].opcode, token, (strlen(token) - 1)) == 0)
		{
			artype[i].f(sta, line_n);
			break;
		}
		i++;
	}
	if (!artype[i].opcode)
	{
		free_stack(sta);
		fprintf(stderr, "L%u: unknown instruction %s\n", line_n, artype[i].opcode);
		exit(EXIT_FAILURE);
	}
}
/**
 * atoi_comp - compares atoi.
 * @str: str value.
 * Return: flag.
 */
int atoi_comp(char *str)
{
	int flag = 0, i = 0;

	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			flag = 0;
		else
		{
			flag = 1;
			break;
		}
		i++;
	}
	return (flag);
}
/**
 * free_stack - free the stack
 * @stack: stack
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		if (!tmp->next)
		{
			free(tmp);
			tmp = NULL;
		}
		else
		{
			tmp = tmp->next;
			free(tmp->prev);
		}
	}
}
