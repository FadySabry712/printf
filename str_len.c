#include "main.h"

/*
* _str_len - find the length of a str
* @s: str pointer
* Return: 0 Sucess
*/

int _str_len(char *s)
{
int n;

for (n = 0; s[n] != 0; n++)
;
return (n);
}

/*
* _str_len_cons - find a length of a str but for a constant pointer
* @s: constant pointer
* Return: 0 Sucess
*/

int _str_len_cons(const char *s)
{
int n;

for (n = 0; s[n] != 0; n++)
;
return (n);
}
