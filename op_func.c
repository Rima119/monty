#include "monty.h"

/** 
   * push - pushes a node to the top of stack 
   * @stack: pointer to the head node pointer of stack 
   * @line_number: the line number
   * Return: Nothing. 
   */

void push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{	
    stack_t *new;
    
    arg.arg = 0;
    (void)line_number;
	new = malloc(sizeof(stack_t));	
    if (new == NULL)	
    {		
           dprintf(STDERR_FILENO, "Error: malloc failed\n");		
           exit(EXIT_FAILURE);	
     }
	new->next = *stack;	
    new->prev = NULL;	
    new->n = arg.arg;	/*Fix the int*/
    if (*stack != NULL)	/* If the stack is not empty*/	
          (*stack)->prev = new;	
    *stack = new;
    arg.length_SQ++; 
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
	temp = *stack;

    if (is_empty_stack(stack))
    {
        dprintf(STDERR_FILENO, "The stack is empty\n");
        exit(EXIT_FAILURE);
    }

    while (!is_empty_stack(stack))	
    {		
        printf("%d\n", temp->n);	
        temp = temp->next;
    }
}
