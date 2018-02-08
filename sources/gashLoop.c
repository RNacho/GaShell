#include "../headers/gashLoop.h"

void gashLoop(char *userName, char *computerName)
{
	char *input = calloc(1, sizeof(char));
	char **arguments = calloc(1, sizeof(char *));
	bool keepGoing = true;
	size_t argumentCount = 0;
	size_t i = 0;

	*arguments = calloc(1, sizeof(char));

	do{
		printf("[%s@%s]$ ",userName,computerName);

		readStdin(&input);
		argumentCount = splitString(&input,&arguments);

		for(i = 0; i < argumentCount; i++){
			puts(*(arguments+i));
		}

		//keepGoing = executeCommand(arguments);
		keepGoing = false; //BORRAR

	} while(keepGoing);

	free(input);
	free(arguments);
}
