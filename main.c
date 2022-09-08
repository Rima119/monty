#include "monty.h"

/**
 * bufze - store the buf in an array
 * @b: the buffer
 * @array: the stored array buffer
 * Return: Length of the array
 */


void bufze(char *b, char **array)
{
	array[0] = strtok(b, " \t\r\n");
	array[1] = strtok(NULL, " \t\r\n");
}

/**
 * _isalpha - function that checks for alphabetic character
 * @c: The character in ASCII code
 * Return: 1 if c is lowercase or uppercase, 0 otherwise
 */

int _isalpha(char *c)
{
	while (*c)
	{
		if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
			return (1);
		c++;
	}
	return (0);
}

/**
 * app_func - execute the correct function
 * @stack: pointer to the head node pointer of stack
 * @array: array
 * @line_number: the line number
 */

void app_func(stack_t **stack, char **array, unsigned int line_number)
{
	unsigned int number;
	void (*func)(stack_t **sta, unsigned int l_number);

	if (array[1] != NULL)
		number = atoi(array[1]);
	else
		number = 0;

	if (!array[0] || array[0][0] == '#')
		return;

	if (strcmp(array[0], "push") == 0 && (!array[1] || _isalpha(array[1])))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		if (stack)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (strcmp(array[0], "push") == 0)
	{
		push(stack, number);
		return;
	}

	func = get_op_func(array[0]);
	if (func)
		func(stack, line_number);
	else if (!func && strcmp(array[0], "\n") != 0)
	{

		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, array[0]);
		if (*stack)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * main - Entry point
 * @argc: argument count
 * @argv: arguments v
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	int num = 0;
	stack_t *stack = NULL;
	FILE *file;
	char buff[1024], *array[100];
	size_t bulen = 1024;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(buff, bulen, file) != NULL)
	{
		num++;

		if (strcmp(buff, "\n") == 0)
			continue;
		bufze(buff, array);
		app_func(&stack, array, num);
	}
	fclose(file);
	if (stack)
		free_stack(&stack);
	return (0);
}
