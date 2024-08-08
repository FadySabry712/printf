#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer
 * @types: List a of arg
 * @buffer: Buffer array to handle print
 * @flags:  Calculates flags
 * @width: get widt
 * @precision: Precision spec
 * @size: Size spec
 * Return: Number of cha
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_char = 0, padding = ' ';
	int in = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long number_addrs;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	number_addrs = (unsigned long)address;

	while (number_addrs > 0)
	{
		buffer[in--] = map_to[number_addrs % 16];
		number_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (flags & F_PLUS)
		extra_char = '+', length++;
	else if (flags & F_SPACE)
		extra_char = ' ', length++;

	in++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, in, length,
		width, flags, padding, extra_char, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hex of non printable chars
 * @types: Lista of argu
 * @buffer: Buffer array to handle print
 * @flags:  Calculatesflags
 * @width: get widt
 * @precision: Precision spe
 * @size: Size spec
 * Return: Number of cha
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0, set = 0;
	char *ptr = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (ptr == NULL)
		return (write(1, "(null)", 6));

	while (ptr[j] != '\0')
	{
		if (is_printable(ptr[j]))
			buffer[j + set] = ptr[j];
		else
			set += append_hexa_code(ptr[j], buffer, j + set);

		j++;
	}

	buffer[j + set] = '\0';

	return (write(1, buffer, j + set));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string
 * @types: Lista of arg
 * @buffer: Buffer arr
 * @flags:  Calculates  flags
 * @width: get width
 * @precision: Precision spe
 * @size: Size spec
 * Return: Numbers of chars
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *ptr;
	int j, counter = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	ptr = va_arg(types, char *);

	if (ptr == NULL)
	{
		UNUSED(precision);

		ptr = ")Null(";
	}
	for (j = 0; ptr[j]; j++)
		;

	for (j = j - 1; j >= 0; j--)
	{
		char z = ptr[j];

		write(1, &z, 1);
		counter++;
	}
	return (counter);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a str in rot13
 * @types: Lista of arg
 * @buffer: Buffer arr
 * @flags:  Calculates flags
 * @width: get width
 * @precision: Precision spec
 * @size: Size spec
 * Return: Numbers of char
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char a;
	char *ptr;
	unsigned int j, i;
	int counter = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	ptr = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (ptr == NULL)
		ptr = "(AYY)";
	for (j = 0; ptr[j]; j++)
	{
		for (i = 0; in[i]; i++)
		{
			if (in[i] == ptr[j])
			{
				a = out[i];
				write(1, &a, 1);
				counter++;
				break;
			}
		}
		if (!in[i])
		{
			a = ptr[j];
			write(1, &a, 1);
			counter++;
		}
	}
	return (counter);
}

