#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#include "main.h"

char *version = "1.0";

static void usage(const char *name)
{
	printf("Usage: %s [-h] [-v] [-p]\n\n", name);
	printf(" -h, --help     Show this text\n");
	printf(" -v, --version  Version is %s\n", version);
	printf(" -p, --print    Print kset if input is kset\n");
}

int sum(int first, int second)
{
	int sum = 0;

	sum = first + second;

	return sum;
}

int main(int argc, char **argv)
{
	char *input = NULL;
	int opt_i;
	int c;
printf("###########################\n");
	struct option opt[] = {
		{ "help", no_argument, 0, 'h' },
		{ "version", no_argument, 0, 'v' },
		{ "print", required_argument, 0, 'p' },
		{ 0, 0, 0, 0 }
	};

	while ((c = getopt_long(argc, argv, "h:v:p", opt, &opt_i)) != -1) {
		switch (c) {
		case 'h':
			break;
		case 'v':
			break;
		case 'p':
			input = optarg;
			break;
		default:
			usage(argv[0]);
			return -1;
		}
	}

	if (!input)
		goto out;

	if (strcmp(input, "kset"))
		goto error;

	printf("The input is %s\n", input);
	printf("The end");

out:
	return 0;

error:
	usage(argv[0]);
	return -1;
}
