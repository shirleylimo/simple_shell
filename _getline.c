#include "header.h"
/**
 *_getline - takes string as an input from stream
 *@lineptr: buffer which stores the input
 *@n: size of the buffer
 *@stream: the stream to read from
 *Return: the number of character read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
static ssize_t input;
	ssize_t ret;
	char c = 'x', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 120)
			buffer = realloc(buffer, input, input + 1);

		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';
	assign_lineptr(lineptr, n, buffer, input);
	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}
