#include "monty.h"

/**
 * push - pushes a node to the top of stack
 * @stack: pointer to the head node pointer of stack
 * @line_number: the line number
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (!stack)
		return;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->prev = NULL;
	new->n = line_number;
	if (!(*stack))
	{
		(*stack) = new;
		return;
	}
	new->next = *stack;
	*stack = new;
}

/**
 * pall - prints the data of all nodes in stack
 * @stack: pointer to the head node pointer of stack
 * @line_number: the line number
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)(line_number);
	temp = *stack;

	if (!temp)
	{
		return;
	}
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to the head node pointer of stack
 * @line_number: the line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the head node pointer of stack
 * @line_number: the line number
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *p1;

	p1 = *stack;
	if (p1->next)
	{
		p1->next->prev = NULL;
	}
	free(p1);
}

/**
 * nop - doesn’t do anything.
 * @stack: pointer to the head node pointer of stack
 * @line_number: the line number
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
