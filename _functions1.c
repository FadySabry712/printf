#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned num
 * @types: List a of argu
 * @buffer: Buffer arr
 * @flags:  Calculates  flags
 * @width: get widt
 * @precision: Precision spe
 * @size: Size spec
 * Return: Number of char
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal
 * @types: Lista of arg
 * @buffer: Buffer arr
 * @flags:  Calculates flags
 * @width: get widt
 * @precision: Precision spec
 * @size: Size spec
 * Return: Number of char
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int j = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[j--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && init_number != 0)
		buffer[j--] = '0';

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal
 * @types: Lista of arg
 * @buffer: Buffer arr
 * @flags:  Calculates flags
 * @width: get width
 * @precision: Precision spec
 * @size: Size spec
 * Return: Number of char
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal
 * @types: Lista of arg
 * @buffer: Buffer ar
 * @flags:  Calculates flags
 * @width: get widt
 * @precision: Precision spec
 * @size: Size spec
 * Return: Number of char
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal numb
 * @types: Lista of arg
 * @map_to: Array of values to map the n
 * @buffer: Buffer arr
 * @flags:  Calculates flags
 * @flag_ch: Calculates flags
 * @width: get width
 * @precision: Precision spec
 * @size: Size spec
 * @size: Size spec
 * Return: Number of char
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[j--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & F_HASH && init_number != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

