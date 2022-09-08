#include "monty.h"

/**
 * tokenize - split the buf and store it in an array
 * @buf: buffer to be split
 * @arr: array buffer to be store in
 * Return: Length of the array
 */


void tokenize(char *buf, char **arr)
{
	arr[0] = strtok(buf, " \t\r\n");
	arr[1] = strtok(NULL, " \t\r\n");
}

/**
 * istherealpha - check if there is an alphabet in a string
 * @s: string to check
 * Return: 1 if True or ) if False
 */

int istherealpha(char *s)
{
	while (*s)
	{
		if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
			return (1);
		s++;
	}

	return (0);
}

/**
 * execute_func - executes the rightful monty function
 * @stack: head of stack
 * @arr: array of tokenize values
 * @line: current line of execution
 * Return: Nothing when found, Terminate the program when no function is found
 */

void execute_func(stack_t **stack, char **arr, unsigned int line)
{
	unsigned int num;
	void (*func)(stack_t **top, unsigned int number);

	if (arr[1] != NULL)
		num = atoi(arr[1]);
	else
		num = 0;

	if (!arr[0] || arr[0][0] == '#')
		return;

	if (strcmp(arr[0], "push") == 0 && (!arr[1] || istherealpha(arr[1])))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		if (stack)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (strcmp(arr[0], "push") == 0)
	{
		push(stack, num);
		return;
	}

	func = get_func(arr[0]);
	if (func)
		func(stack, line);
	else if (!func && strcmp(arr[0], "\n") != 0)
	{

		fprintf(stderr, "L%d: unknown instruction %s\n", line, arr[0]);
		if (*stack)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * main - main function
 * @argc: argument count
 * @argv: arguments v
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	int line_number = 0;
	stack_t *stack = NULL;
	FILE *fp;
	char buf[1024], *arr[100];
	size_t buflen = 1024;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(buf, buflen, fp) != NULL)
	{
		line_number++;

		if (strcmp(buf, "\n") == 0)
			continue;
		tokenize(buf, arr);
		execute_func(&stack, arr, line_number);
	}
	fclose(fp);
	if (stack)
		free_stack(&stack);
	return (0);
}
