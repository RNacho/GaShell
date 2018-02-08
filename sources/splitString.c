#include "../headers/splitString.h"

size_t splitStringWith(char **input, char ***output, char **delimiter)
{
	size_t element = 0;
	size_t index = 0;
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;
	bool found = 0;
	bool repeated = 0;
	bool written = 0;

	for(i = 0; i < strlen(*input); i++){
		found = 0;
		repeated = 0;

		for(j = 0; j < strlen(*input); j++){
			if( *((*input) + i) == *((*delimiter) + j) ){
				found = true;
				for(k = 0; k < strlen(*input); k++){
					if( *((*input) + i + 1) == *((*delimiter) + k) ){
						repeated = true;
					}
				}
			}
		}

		if(found && !repeated && written){
			++element;
			index = 0;
			(*output) = realloc ((*output), (element + 1) * sizeof(char *));
		}

		if(!found){
			*((*output) + element) = realloc ((*((*output) + element)), (index + 1) * sizeof(char));
			*(*((*output) + element) + index) = *((*input) + i);
			++index;
			written = true;
		}
	}

	return (element + 1);
}

size_t splitString(char **input, char ***output)
{
	char *delimiter = " \r\a\n\t";
	return splitStringWith(input, output, &delimiter);
}
