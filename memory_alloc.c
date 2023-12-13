#include "monty.h"

/**
 * create_inst - Creates a new instruction_t
*/
void create_inst(void)
{
	info->instr = malloc(sizeof(instruction_t));
	if (info->instr == NULL)
	{
		malloc_error();
	}
}

/**
 * create_info - Creates a new info_t
*/
void create_info(void)
{
	info = malloc(sizeof(info_t));
	if (info == NULL)
	{
		malloc_error();
	}
}

/**
 * initialize_info - Initializes the info_t struct
 */
void initialize_info(void)
{
	create_info();
	create_inst();

	info->line_number = 0;
	info->token_number = 0;
	info->elements = 0;
	info->file = NULL;
	info->filename = NULL;
	info->line = NULL;
	info->tokens = NULL;
	info->stack = NULL;
}

/**
 * create_stack - Create a new stack
*/
void create_stack(void)
{
	info->stack = malloc(sizeof(stack_t));
	if (info->stack == NULL)
	{
		malloc_error();
	}
	info->stack->next = NULL;
	info->stack->prev = NULL;
}

/**
 * alloc_tokens - Allocates memory to the tokens (args)
*/
void alloc_tokens(void)
{
	info->tokens = malloc(sizeof(char *) * (info->token_number + 1));
	if (info->tokens == NULL)
	{
		malloc_error();
	}
}