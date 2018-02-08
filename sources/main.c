/* This is just a dummy main intended for test
 * of the library itself, if you plan to compile
 * the library from source, follow the instructions
 * at readme, do not compile this main
 */

#include "../headers/main.h"

int main(void)
{
	char *user="Nacho";
	char *computer="Torre";

	//Read config files
	//readConfigs();

	//Start the shell
	gashInteractive(user,computer);

	//Clean and terminate
	//gashExit();

	return EXIT_SUCCESS;
}
