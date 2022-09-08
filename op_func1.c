#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to the head node pointer of stack
 * @line_number: the line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int pl;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	pl = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = pl;
}

/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to the head node pointer of stack
 * @line_number: the line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *pl;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	free(*stack);
	*stack = pl;
}
