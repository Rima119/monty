#include "monty."
/**
 * free_stack - clear a stack
 * @head: double pointer
 */

void free_stack(stack_t **head)
{
	stack_t *curr;
	stack_t *next;

	current = *head;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

