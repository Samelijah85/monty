#include "monty.h"
/**
 * execute - Executes the opcode
 * @stack: Top element of the stack
 * @counter: Line_counter
 *
 * Return: 1 on success
 */
int execute(stack_t **stack, unsigned int counter)
{
	instruction_t opst[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};
	unsigned int i = 0;
	char *op;

	op = strtok(info.line, " \n\t");
	if (op && op[0] == '#')
		return (0);
	info.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		opcode_error(stack, counter, op);
	}
	return (1);
}
