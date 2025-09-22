#include <stdio.h> 
#include <stdlib.h>
#include "lib/plib.h"

void _exit(int code);
void help(void);
int post(void);

// handle arguments
int main(const int argc, const char *argv[]){
	// SET ARGUMENTS ==========================
	pl_arg *help_a = PL_A(
			.name = "--help",
			.description = "Show this dialog"
			); 

	pl_arg *xine_a = PL_A(
			.name = "--dual",
			.description = "fills wallpaper over two monitors",
			);

	pl_arg *geom_a = PL_A(
			.name = "--geometry",
			.description = "set custom mpv geometry eg 1920x1070+0+0",
			.takes_value = TAKES_VALUE,
			);

	pl_arg *zoom_a = PL_A(
			.name = "--zoom",
			.description = "set video zoom, default 0.0",
			.takes_value=TAKES_VALUE,
			);

	pl_arg *volm_a = PL_A(
			.name = "--volume",
			.description = "set video volume, default 0",
			.takes_value = TAKES_VALUE,
			);
	
	// INIT PLIB ==============================
	const pl_return_type ret = PL_PROC();
	if(ret != PL_SUCCESS){
		help();
		
		// HANDLE ERROR =========================
		printf("%s caused by '%s'\n",
				pl_return_type_string[ret], 
				PL_LAST_ARG);

		exit(1);
	} else {
		// argument parse completed move on.. 
		exit(post());
	}

	exit(0);
}

void help() {
	printf("motionlayer [options]\noptions:\n");
	pl_help();
}

void _exit(int code){
	printf("exiting\n");
	pl_exit();
	exit(code);
}

int post(){
	if(pl_arg_run(pl_arg_get("--help")) == PL_SUCCESS) 
		help();


	return 0;
}
