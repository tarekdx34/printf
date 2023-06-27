#include "main.h"
/*print character **/
/**
 * print_char - prints a char
 * @types List arguments
 * @buffer array to handle print
 * @flags
 * @width
 * @precision
 * @size: size specifier
 * Return number of chars
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char cc = va_arg(types, int);

	return (handle_write_char(cc, buffer, flags, width, precision, size));
}
/** print strng
 * print_string - Prints a string
 * @types List of arguments
 * @buffer array to handle print
 * @flags
 * @width
 * @precision
 * @size: size specifier
 * Return number of chars
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, length = 0;
	char *strr = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (strr == NULL)
	{
		strr = "(null)";
		if (precision >= 6)
			strr = "      ";
	}

	while (strr[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &strr[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &strr[0], length);
			return (width);
		}
	}

	return (write(1, strr, length));
}
/**print %
 * print_percent - Prints a percent sign
 * @types List a of arguments
 * @buffer array to handle print
 * @flags
 * @width
 * @precision
 * @size: size specifier
 * Return number of chars
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/*** print integer
 * print_int - Print int
 * @types List a of arguments
 * @buffer array to handle print
 * @flags
 * @width
 * @precision
 * @size: size specifier
 * Return number of chars
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int is_negative = 0;
	int i = BUFF_SIZE - 2;
	long int n = va_arg(types, long int);
	unsigned long int numm;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numm = (unsigned long int)n;

	if (n < 0)
	{
		numm = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (numm > 0)
	{
		buffer[i--] = (numm % 10) + '0';
		numm /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**print binary
 * print_binary - Prints an unsigned number
 * @types: arguments
 * @buffer: Buffer array to handle print
 * @flags active flags
 * @width: get width.
 * @precision: Precision
 * @size: Size 
 * Return
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
