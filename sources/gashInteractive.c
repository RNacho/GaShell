#include "../headers/gashInteractive.h"

void gashInteractive(char *userName, char *computerName)
{
	bool keepGoing = true;
	size_t i = 0;
	size_t argumentCount = 0;
	char *input = NULL;
	char **arguments = NULL;


	do {
		input = calloc(1, sizeof(char));
		arguments = calloc(1, sizeof(char *));
		*arguments = calloc(1, sizeof(char));

		printf("[%s@%s]$ ", userName, computerName);

		readStdin(&input);
		puts("Este es el input:");
		puts(input);

		printf("Este es el argcount viejo: %ld\n", argumentCount);
		argumentCount = splitString(&input, &arguments);
		printf("Este es el argcount nuevo: %ld\n", argumentCount);

		puts("Estos son los argumentos nuevos:");
		for (i = 0; i < argumentCount; i++)
			puts(*(arguments + i));

		keepGoing = executeCommand(argumentCount, &arguments);

		for (i = 0; i < argumentCount; i++)
			memset(*(arguments + i), '\0', strlen(*(arguments + i)));

		free(input);
		input = NULL;
	
		for (i = 0; i < argumentCount; i++) {
			free(*(arguments + i));
			*(arguments + i) = NULL;
		}
	
		free(arguments);
		arguments = NULL;

	} while (keepGoing);

}
