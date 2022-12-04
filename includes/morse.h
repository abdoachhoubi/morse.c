#ifndef MORSE_H
# define MORSE_H

#include <sys/cdefs.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int, char *[]);
void morse(int);
void decode(const char *);

#endif