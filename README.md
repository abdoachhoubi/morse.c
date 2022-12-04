# C MORSE
C MORSE is a MORSE to ASCII converter and vice versa.
<br />

## How to use?

Clone the repo to your local machine and run the command `make`<br/>
This will produce a new program called `morse`.<br />
Usage:<br />

```bash
# SYNOPSIS
./morse -s [string1]	[string2]	[string3]	...
./morse -d [morse rep1]	[morse rep2]	[morse rep3]	...

# DESCRIPTION
# -s: converts a string into morse code
# -d: converts a morse code into string
```

## MORSE Code table:

```c
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
```


**All contributions are welcomed!**
