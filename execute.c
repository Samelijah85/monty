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
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", f_queue},
		{"stack", f_stack},
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
		opcode_error(stack, counter, op);
	return (1);
}
