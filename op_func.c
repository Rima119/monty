#include "monty.h"

/**
 * push: pushes an element to the stack
 * @stack: pointer to the first element in a stack
 * @line_number: the line within the stuck
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *nw;
	
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}
	nw = malloc(sizeof(stack_t));
	if (nw == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	nw->next = *stack;
	nw->prev = NULL;
	nw->n = arg.arg;
	if (*stack)
		(*stack)->prev = nw;
	*stack = nw;
}

/**
 * pall - prints all the values on the stack starting from the top of the stack
 * @stack: pointer to the first element in a stack
 * @line_number: the line within the stuck
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
