#include "../headers/readStdin.h"

void readStdin(char **output)
{
	int buffer = 0;
	int inputLength = 0;

	for (buffer = getchar(); buffer != '\n' && buffer != EOF; inputLength++) {
		*output = realloc(*output, (inputLength + 1) * sizeof(char));
		*(*output + inputLength) = (char) buffer;
		buffer = getchar();
	}
}
