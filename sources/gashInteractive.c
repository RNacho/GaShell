#include "../headers/gashInteractive.h"

void gashInteractive(char *userName, char *computerName)
{
	bool keepGoing = true;
	size_t i = 0;
	size_t argumentCount = 0;
	char *input = calloc(1, sizeof(char));
	char **arguments = calloc(1, sizeof(char *));
	
	*arguments = calloc(1, sizeof(char));

	do{
		input = realloc(input, sizeof(char));
		*arguments = realloc(*arguments, sizeof(char));
		arguments = realloc(arguments, sizeof(char *));

		printf("[%s@%s]$ ",userName,computerName);

		readStdin(&input);
		argumentCount = splitString(&input,&arguments);

		for(i = 0; i < argumentCount; i++){
			puts(*(arguments+i));
		}

		keepGoing = executeCommand(argumentCount, &arguments);

	} while(keepGoing);

	free(input);
	for(i = 0; i < argumentCount; i++){
		free(*(arguments + i));
	}
	free(arguments);

}
