#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
/* Flags */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)
/* Length */
#define SHORT 1
#define LONG 2
/**
*struct buffer_s - new type
*@buffer: pointer to char array
*@start: pointer to buffer start
*@len: length of string
*/
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;
/**
*struct converter_s - new type
*@specifier: char specifier
*@func: pointer to conversion function
*/
typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list, buffer_t *, unsigned char, int, int, unsigned char);
} converter_t;
int _printf(const char *format, ...);
int _putchar(char c);

#endif
