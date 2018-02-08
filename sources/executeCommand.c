#include "../headers/executeCommand.h"

bool executeCommand(size_t argumentCount, char ***arguments)
{
	if (argumentCount == 1 && strcmp(*((*arguments)+0), "exit") == 0)
		return false;
	else
		return true;
}
