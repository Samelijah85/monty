#include "monty.h"

/**
 * push_error - Handles push errors
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void push_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * opcode_error - Handles opcode errors
 * @stack: Pointer to the pointer to the head of the list
 * @counter: The line number
 * @op: The opcode
 */
void opcode_error(stack_t **stack, unsigned int counter, char *op)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * pint_error - Handles pint errors
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void pint_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * pop_error - Handles pop errors
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void pop_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * div_by_zero_error - Handles errors when a number is being divided by zero
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void div_by_zero_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
