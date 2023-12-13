#include "monty.h"

/**
 * no_argument_error - prints error when no arguments was found
*/
void no_argument_error(void)
{
	fprintf(stderr, "L%u: usage: push integer\n", info->line_number);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * empty_stack_error - prints error when pinting an empty stack
 * @opcode: the opcode (instruction)
*/
void empty_stack_error(char *opcode)
{
	fprintf(stderr, "L%u: can't %s, stack empty\n", info->line_number, opcode);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * pop_empty_stack_error - prints error when poping an empty stack
*/
void pop_empty_stack_error(void)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", info->line_number);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * stack_too_short_error - prints error when stack is too short
 * @opcode: the opcode (instruction)
*/
void stack_too_short_error(char *opcode)
{
	unsigned int line = info->line_number;

	fprintf(stderr, "L%u: can't %s, stack too short\n", line, opcode);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * div_by_zero_error - prints error when top element is 0
*/
void div_by_zero_error(void)
{
	fprintf(stderr, "L%u: division by zero\n", info->line_number);
	free_all();
	exit(EXIT_FAILURE);
}
