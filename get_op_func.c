#include "monty.h"
/**
 * get_opcode - Check if opcode is a valid opcode
 * @opcode: opcode to check
 * @stack : double pointer to the beginnig of the stack
 * @line_number :  script line number
 */
void (*get_opcode(char *s))(stack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t opcode_arr[] = {{"push", push}, {"pall", pall}, {NULL, NULL}
	};

	for (i = 0; opcode_arr[i].opcode; i++)
	{
		if (strcmp(opcode_arr[i].opcode, s) == 0)
			break;
	}
	return (opcode_arr[i].f);
}
