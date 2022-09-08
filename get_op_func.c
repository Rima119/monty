#include "monty.h"

/**
 * get_func - Check if opcode is a valid opcode and apply associated processing if yes
 * @opcode : opcode to check
 * Return: the function associated with an opcode or Null on failure
 */

void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t inst[] = {
		{"push", push},
		{"pall", pall},
	};

	const int LEN = 14;
	int i = 0;

	while (i < LEN)
	{
		if (strcmp(opcode, inst[i].opcode) == 0)
			return (inst[i].f);
		i++;
	}

	return (NULL);
}