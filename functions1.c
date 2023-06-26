#include "main.h"
/**print unsigned number**/
/**
 * print_unsigned prints unsigned number
 * @types
 * @buffer
 * @flags
 * @width
 * @precision
 * @size
 * return
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0'; /** NULL */

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**print unigned number in octal**/
/**
 * print_octal
 * @types
 * @buffer
 * @flags
 * @width
 * @precision
 * @size
 * return
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int initnum = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && initnum != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**print unsigned number in hex**/
/**
 * print_hexadecimal
 * @types
 * @buffer
 * @flags
 * @width
 * @precision
 * @size
 * return
 */
int print_hexadecimal(va_list types, char buffer[],
		 int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				 flags, 'x', width, precision, size));
}

/**print unsigned hex upper
 * print_hexa_ipper
 * @buffer
 * @flags
 * @width
 * @precision
 * @size
 * return
 */
int print_hexa_upper(va_list types, char buffer[],
	       	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
			  	flags, 'X', width, precision, size));
}

/**print hex in lower or upper**/
/**
 * print_hexa
 * @types
 * @buffer
 * @flags
 * @width
 * @precision
 * @size
 * return
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int initnum = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & F_HASH && initnum != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
