#include "monty.h"

/**
 * malloc_error - prints error when malloc fails
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * usage_error - prints proper usage of the program
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * open_file_error - prints error when file fail to open
 */
void open_file_error(void)
{
	fprintf(stderr, "Error: Can't open file %s\n", info->filename);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * invalid_instruction_error - prints error if the program encounters
 * an invalid instruction
 * @opcode: the opcode (instruction)
 */
void invalid_instruction_error(char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", info->line_number, opcode);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * out_of_range_error - prints error when value is not in
 * the ascii table
*/
void out_of_range_error(void)
{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", info->line_number);
	free_all();
	exit(EXIT_FAILURE);
}
