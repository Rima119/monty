#include "monty.h"

/** 
   * push - pushes a node to the top of stack 
   * @stack: pointer to the head node pointer of stack 
   * @line_number: the line number
   * Return: Nothing. 
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
	}	/* If the stack is not empty*/	
          	
    new->next = *stack;
	*stack = new;
}
/** 
   * pall - prints the data of all nodes in stack 
   * @stack: pointer to the head node pointer of stack 
   * @line_number: the line number
   * Return: Nothing.
   */
void pall(stack_t **stack, unsigned int line_number)
{		
	stack_t *temp;

    (void)(line_number);

    if (*stack == NULL)
    {
        return;
    }
	temp = *stack;
	
    while (temp)	
    {		
        printf("%d\n", temp->n);	
        temp = temp->next;
    }
}
