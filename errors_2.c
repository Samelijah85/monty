#include "monty.h"

/**
 * swap_error - Handles swap errors
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void swap_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * add_error - Handles add errors
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void add_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * sub_error - Handles sub errors
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void sub_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * div_error - Handles div errors
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void div_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * mul_error - Handles mul errors
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void mul_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	fclose(info.file);
	free(info.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
