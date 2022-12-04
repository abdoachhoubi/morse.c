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

static void    show(const char *s)
{
	printf(" %s", s); 
}

void    morse(int c)
{
	int i;

	if (isalpha(c))
		show(alph[c - (isupper(c) ? 'A' : 'a')]);
	else if (isdigit(c))
		show(digit[c - '0']);
	else if (isspace(c))
		show("");  /* could show BT for a pause */
	else {
		i = 0;
		while (other[i].c) {
			if (other[i].c == c) {
				show(other[i].morse);
				break;
			}
			i++;
		}
	}
}