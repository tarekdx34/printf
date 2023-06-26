#include "main.h"
/**
 * get_width calculates the width
 * @format
 * @i
 * @list
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int widthh = 0;
	int currenti;

	for (currenti = *i + 1; format[currenti] != '\0'; currenti++)
	{
		if (is_digit(format[currenti]))
		{
			widthh *= 10;
			widthh += format[currenti] - '0';
		}
		else if (format[currenti] == '*')
		{
			currenti++;
			widthh = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = currenti - 1;

	return (widthh);
}
