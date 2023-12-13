#include "monty.h"

/**
 * execute - executes the opcode
*/
void execute(void)
{
	info->instr->f(&info->stack, info->line_number);
}
