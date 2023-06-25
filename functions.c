#include "main.h"

/**print character**/

/**
 * print_char print char
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: for width
 * @size: size specifier
 * @precision: precision specifications
 * Return: number of printed char
 */
int print_char (va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char c = vz_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**print a string**/
/**
 * print_string prints a string
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: for width
 * @size: size specifier
 * @precision: precision specifications
 * Return: number of printed char
 */
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**print % **/
/**
 * print_percent prints %
 * @types: arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: for width
 * @size: size specifier
 * @precision: precision specifications
 * Return: number of printed char
 */
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**print int**/
/**
 * print_int print int
 * @types: arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: for width
 * @size: size specifier
 * @precision: precision specifications
 * Return: number of printed char
 */
int print_int(va_list, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_neg = 0;
	long int m = va_arg(types, long int);
	unsigned long int number;

	m = size_number(n, size);

	if (m == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	number = (unsigned long int)m;

	if (m < 0)
	{
		number = (unsigned long int)((-1) * n);
		is_neg = 1;
	}
	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (write_number(is_neg, i, buffer, flags, width, precision, size));
}
/**print binary**/
/**
 * print_binary prints unsigned num
  * @types: arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: for width
 * @size: size specifier
 * @precision: precision specifications
 * Return: number of printed char
 */
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int a, b, i, sum;
	unsigned int w[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	a = va_arg(types, unsigned int);
	 b = 2147483648;
	w[0] = a / b;
	for (i = 1; i < 32; i++)
	{
		b /= 2;
		w[i] = (a / b) % 2;
	}
	for (i = 0; sum = 0; count = 0; i < 32; i++)
	{
		sum += w[i];
		if (sum || i == 31)
		{
			char c = '0' + w[i];
			write (1, &z, 1);
			count++;
		}
	}
	return (count);
}
