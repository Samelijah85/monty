#include "monty.h"

/**
 * get_stream - reads the file contents
*/
void get_stream(void)
{
	size_t len;

	info->file = fopen(info->filename, "r");
	if (info->file == NULL)
	{
		open_file_error();
	}

	while (getline(&(info->line), &len, info->file) != -1)
	{
		info->line_number += 1;
		tokenize_input();
		if (info->token_number == 0)
		{
			continue;
		}

		if (info->tokens[0][0] == '#')
		{
			free_tokens();
			continue;
		}

		get_instruction();
		execute();
		free_tokens();
	}
	free_all();
}

/**
 * close_stream - closes the file
*/
void close_stream(void)
{
	if (info->file)
	{
		fclose(info->file);
	}
}
