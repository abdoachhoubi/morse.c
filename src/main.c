#include "../includes/morse.h"

int	sflag;
int	dflag;

static void    show(const char *s)
{
	if (sflag)
		printf(" %s", s);
	else for (; *s; ++s)
		printf(" %s", *s == '.' ? "dit" : "daw");
	printf("\n");
}

int main(int argc, char **argv)
{
	int ch;
	char *p;

	/* Revoke setgid privileges */
	setgid(getgid());

	while ((ch = getopt(argc, argv, "ds")) != -1)
		switch((char)ch) {
		case 'd':
			dflag = 1;
			break;
		case 's':
			sflag = 1;
			break;
		case '?':
		default:
			fprintf(stderr, "usage: morse [-ds] [string ...]\n");
			exit(1);
		}
	argc -= optind;
	argv += optind;

	if (dflag) {
		if (*argv) {
			do {
				decode(*argv);
			} while (*++argv);
		} else {
			char foo[10];	/* All morse chars shorter than this */
			int is_blank, i;

			i = 0;
			is_blank = 0;
			while ((ch = getchar()) != EOF) {
				if (ch == '-' || ch == '.') {
					foo[i++] = ch;
					if (i == 10) {
						/* overrun means gibberish--print 'x' and
						 * advance */
						i = 0;
						putchar('x');
						while ((ch = getchar()) != EOF &&
							(ch == '.' || ch == '-'))
							;
						is_blank = 1;
					}
				} else if (i) {
					foo[i] = '\0';
					decode(foo);
					i = 0;
					is_blank = 0;
				} else if (isspace(ch)) {
					if (is_blank) {
						/* print whitespace for each double blank */
						putchar(' ');
						is_blank = 0;
					} else
						is_blank = 1;
				}
			}
		}
		putchar('\n');
	} else {
		if (*argv)
			do {
				for (p = *argv; *p; ++p)
					morse((int)*p);
				show("");
			} while (*++argv);
		else while ((ch = getchar()) != EOF)
			morse(ch);
	}
	
	return 0;
}
