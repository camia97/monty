#include "monty.h"
/**
 *op_push - push to the stack function.
 *@stack: stack.
 *@line_n: number of lines value.
 */
void op_push(stack_t **stack, unsigned int line_n)
{
	char *hola;
	stack_t *new_node;
	int a;
	/* ojo */
	printf("entre al push\n");
	hola = strtok(NULL, " ");
	printf("hola: %s", hola);
	/* end ojo */
	printf("strtok?\n");
	a = atoi(hola);
	printf("%d\n", a);
	(void)line_n;

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
		exit(EXIT_FAILURE);
	printf("llega?\n");
	new_node->n = atoi(hola);
	printf("asigna?\n");
	new_node->next = (*stack);
	printf("add stack?\n");
	new_node->prev = NULL;
	if (*stack)
	{	(*stack)->prev = new_node;
		printf("stackea?\n");
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
