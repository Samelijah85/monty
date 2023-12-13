#include "monty.h"

/**
 * tokenize_input - tokenizes the instruction
 */
void tokenize_input(void)
{
	int i = 0;
	char *line_dup, *token, *delims = " \t\n";

	line_dup = malloc(sizeof(char) * (strlen(info->line) + 1));
	if (line_dup == NULL)
		malloc_error();

	strcpy(line_dup, info->line);
	token = strtok(line_dup, delims);
	if (token == NULL)
	{
		free(line_dup);
		return;
	}

	while (token != NULL)
	{
		info->token_number += 1;
		token = strtok(NULL, delims);
	}

	alloc_tokens();
	strcpy(line_dup, info->line);
	token = strtok(line_dup, delims);
	while (token != NULL)
	{
		info->tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (info->tokens[i] == NULL)
		{
			malloc_error();
		}
		strcpy(info->tokens[i], token);
		token = strtok(NULL, delims);
		i++;
	}
	info->tokens[i] = NULL;
	free(line_dup);
}

/**
 * get_instruction - parses the instruction
 */
void get_instruction(void)
{
	int i = 0;

	instruction_t instruction[] = {
		{"push", &push},
		{"pall", &pall},
		{"pint", &pint},
		{"pop", &pop},
		{"swap", &swap},
		{"add", &add},
		{"nop", &nop},
		{"sub", &sub},
		{"div", &_div},
		{"mul", &mul},
		{"mod", &mod},
		{"pchar", &pchar},
		{"pstr", &pstr},
		{"rotr", &rotr},
		{"rotl", &rotl}
		};

	if (info->token_number == 0)
	{
		return;
	}

	while (i < 15)
	{
		if (strcmp(instruction[i].opcode, info->tokens[0]) == 0)
		{
			info->instr->opcode = instruction[i].opcode;
			info->instr->f = instruction[i].f;
			return;
		}
		i++;
	}
	invalid_instruction_error(info->tokens[0]);
}
