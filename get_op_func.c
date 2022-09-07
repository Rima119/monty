#include "monty.h"
/**
 * get_opcode - Check if opcode is a valid opcode
 * @opcode: opcode to check
 * @stack : double pointer to the beginnig of the stack
 * @line_number :  script line number
 */
void get_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t opcode_arr[] = {{"push", m_push}, {"pall", m_pall}, {NULL, NULL}
	};

	for (i = 0; opcode_arr[i].opcode != NULL; i++)
	{
		if (strcmp(opcode_arr[i].opcode, opcode) == 0)
		{
			opcode_arr[i].f(stack, line_number);
			return;
		}
	}
	dprintf(STDERR_FILENO, "L%u: unknow instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
