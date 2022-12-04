#include "../includes/morse.h"

static const char
	*const digit[] = {
	"-----",
	".----",
	"..---",
	"...--",
	"....-",
	".....",
	"-....",
	"--...",
	"---..",
	"----.",
},
	*const alph[] = {
	".-",
	"-...",
	"-.-.",
	"-..",
	".",
	"..-.",
	"--.",
	"....",
	"..",
	".---",
	"-.-",
	".-..",
	"--",
	"-.",
	"---",
	".--.",
	"--.-",
	".-.",
	"...",
	"-",
	"..-",
	"...-",
	".--",
	"-..-",
	"-.--",
	"--..",
};

static const struct punc {
	char c;
	const char *morse;
} other[] = {
	{ '.', ".-.-.-" },
	{ ',', "--..--" },
	{ ':', "---..." },
	{ '?', "..--.." },
	{ '\'', ".----." },
	{ '-', "-....-" },
	{ '/', "-..-." },
	{ '(', "-.--." },
	{ ')', "-.--.-" },
	{ '"', ".-..-." },
	{ '=', "-...-" },
	{ '+', ".-.-." },
	{ '\0', NULL }
};

void    decode(const char *s)
{
	int i;
	
	for (i = 0; i < 10; i++)
		if (strcmp(digit[i], s) == 0) {
			putchar('0' + i);
			return;
		}
	
	for (i = 0; i < 26; i++)
		if (strcmp(alph[i], s) == 0) {
			putchar('A' + i);
			return;
		}
	i = 0;
	while (other[i].c) {
		if (strcmp(other[i].morse, s) == 0) {
			putchar(other[i].c);
			return;
		}
		i++;
	}
	if (strcmp("...-.-", s) == 0)
		return;
	putchar('x');	/* line noise */
}