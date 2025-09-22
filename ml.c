#include <stdio.h> 
#include "lib/plib.h"

void help() {
	printf("motionlayer [options]\noptions:\n");
	pl_help();
}

int main(const int argc, const char *argv[]){
	pl_arg *help_a = PL_A(
			.name = "--help",
			.description = "Show this dialog"
			); 
	
	// init plib 
	const pl_return_type ret = PL_PROC();
	if(ret != PL_SUCCESS){
		help();
		printf("%s -> %s\n",pl_return_type_string[ret],PL_LAST_ARG);
	} else {
		// continue
		printf("passed\n");
	}
	return 0;
}
