#include "monty.h"

/**
 * get_op_func - Check if opcode is a valid opcode
 * @opcode: opcode to check
 * Return: the function associated with an opcode or Null on failure
 */

void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t inst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	while (inst[i].f != NULL)
	{
		if (strcmp(opcode, inst[i].opcode) == 0)
			return (inst[i].f);
		i++;
	}
	return (NULL);
}
