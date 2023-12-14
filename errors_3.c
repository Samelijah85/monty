#include "monty.h"

/**
 * mod_error - Handles mod errors
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void mod_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * pchar_error - Handles pchar errors
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void pchar_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * pchar_out_of_range_error - Handles errors when the number is out of range
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void pchar_out_of_range_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
