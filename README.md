# C MORSE
C MORSE is a MORSE to ASCII converter and vice versa.
<br />

## How to use?

Clone the repo to your local machine and run the command `make`<br/>
This will produce a new program called `morse`.<br />
Usage:<br />
```bash
./morse [-ds] [string ...]
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
